#include "paintscene.h"

paintScene::paintScene(QObject *parent) : QGraphicsScene(parent)
{

}

paintScene::~paintScene()
{

}

void paintScene::clearBack()
{
    clear();
    //_lines.removeLast();
    for(int i = 0; i < _lines.size() - 1; ++i)
        for(int j = 0; j < _lines[i].list.size(); ++j)
            addLine(_lines[i].list[j],_lines[i].pen);
    _lines.removeLast();
}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    addLine(event->scenePos().x() - 5, event->scenePos().y() - 5, 10, 10, QPen(Qt::NoPen));
    _previousPoint = event->scenePos();
    Lines line(_tmpList, QPen(_color,10,Qt::SolidLine,Qt::RoundCap));
    if (_lines.size() == 77)
        _lines.removeFirst();
    _lines.append(line);
    _tmpList.clear();
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QLineF line(_previousPoint.x(), _previousPoint.y(), event->scenePos().x(), event->scenePos().y());
    addLine(line, QPen(_color,10,Qt::SolidLine,Qt::RoundCap));
    _previousPoint = event->scenePos();
    _tmpList.append(line);
}

void paintScene::changeColor()
{
    QColor color = QColorDialog::getColor(_color);
    _color = color;
}

Lines::Lines(QList<QLineF> _list, QPen _pen): list(_list),pen(_pen) {}


