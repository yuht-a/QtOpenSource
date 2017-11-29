#include "butteryfly.h"
#include <QtWidgets/QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene *scene = new QGraphicsScene;
    scene->setSceneRect(QRectF(-400,-300,800,600));
    for(int i=0;i<100;i++)
    { 
        Butterfly *butterfly = new Butterfly; //为每一个飞舞的湖底产生一个随机位置 
        butterfly->setPos((qrand()%int(scene->sceneRect().width()))-400,(qrand()%int(scene->sceneRect().height()))-300); 
        scene->addItem(butterfly); 
    } 
    QGraphicsView *view = new QGraphicsView;
    view->setScene(scene); 
    view->setMaximumSize(800,600);
    view->setMinimumSize(800,600); 
    view->show(); 
    return a.exec();
}
