#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QList>
#include <QDebug>

#include <QWidget>
#include <QColor>
#include <QColorDialog>
#include <QResizeEvent>

class Lines;

class paintScene : public QGraphicsScene
{

    Q_OBJECT

public:
    explicit paintScene(QObject *parent = 0);
    ~paintScene();

public slots:
    void clearBack();
    void changeColor();

private:
    QPointF _previousPoint;
    QList<Lines> _lines;
    QColor _color;
    QList<QLineF> _tmpList;


private:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);   

};

class Lines{

public:
    Lines(QList<QLineF>, QPen);
    QList<QLineF> list;
    QPen pen;
};

#endif // PAINTSCENE_H
