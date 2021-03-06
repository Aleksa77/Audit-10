#ifndef PAINT_H
#define PAINT_H

#include <paintscene.h>

namespace Ui {
class Paint;
}

class Paint : public QWidget
{
    Q_OBJECT

public:
    explicit Paint(QWidget *parent = 0);
    ~Paint();

private:
    Ui::Paint *ui;
    QTimer *timer;
    paintScene *scene;

private:
    void resizeEvent(QResizeEvent * event);

private slots:
    void slotTimer();
};

#endif // PAINT_H
