#include "butteryfly.h"
#include <QtGui>
#include <math.h>
#include <QGraphicsScene>
static const double PI = 3.14;

Butterfly::Butterfly()
{
    QString str= qApp->applicationDirPath() +"\\buttfly.png";
    
    ;
    if(QFile::exists(str))
    {
        pix_up.load(str);
        pix_down.load(str); 
    }

    up = true; 
    startTimer(100); //时间间隔100毫秒
}

void Butterfly::timerEvent(QTimerEvent *)
{
    qreal edgex = scene()->sceneRect().right()+boundingRect().width()/2; 
    qreal edgetop = scene()->sceneRect().top()+boundingRect().height()/2;
    qreal edgebottom = scene()->sceneRect().bottom()+boundingRect().height()/2; 
    if (pos().x() >= edgex) 
        setPos(scene()->sceneRect().left(),pos().y());
    if (pos().y() <= edgetop) setPos(pos().x(),scene()->sceneRect().bottom());
    if (pos().y() >= edgebottom) setPos(pos().x(),scene()->sceneRect().top());
    angle += (qrand()%10)/20.0; 
    qreal dx = fabs(sin(angle*PI)*10.0); 
    qreal dy = (qrand()%20)-10.0; //
    setPos(mapToParent(dx,dy));//映射到场景的坐标 
    update();
}

QRectF Butterfly::boundingRect() const
{
    qreal adjust = 2;
    return QRectF(-pix_up.width()/2-adjust,-pix_up.height()/2-adjust, pix_up.width()+adjust*2,pix_up.height()+2*adjust);
}

void Butterfly::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
 if(up)
 {
     painter->drawPixmap(boundingRect().topLeft(),pix_up);//绘图 
     up = !up; 
 } 
 else
 {   painter->drawPixmap(boundingRect().topLeft(),pix_down);
     up = !up; }
 }
