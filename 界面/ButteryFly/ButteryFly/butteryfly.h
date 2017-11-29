#ifndef BUTTERYFLY_H
#define BUTTERYFLY_H

#include <QtWidgets/QMainWindow>
#include <QGraphicsItem>
#include <QObject>

class Butterfly : public QObject, public QGraphicsItem 
{
    Q_OBJECT 
public: 
    Butterfly();
    void timerEvent(QTimerEvent *);//声明定时器的timerEvent()函数
    QRectF boundingRect() const; //该函数必须实现
protected: 
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //重画函数 
private: 
    bool up; //用于实现蝴蝶的飞舞画面 
    QPixmap pix_up;     //蝴蝶图案一 
    QPixmap pix_down;  //蝴蝶
    qreal angle; 
};

#endif // BUTTERYFLY_H