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
    void timerEvent(QTimerEvent *);//������ʱ����timerEvent()����
    QRectF boundingRect() const; //�ú�������ʵ��
protected: 
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //�ػ����� 
private: 
    bool up; //����ʵ�ֺ����ķ��軭�� 
    QPixmap pix_up;     //����ͼ��һ 
    QPixmap pix_down;  //����
    qreal angle; 
};

#endif // BUTTERYFLY_H