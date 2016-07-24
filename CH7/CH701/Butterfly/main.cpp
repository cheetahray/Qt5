#include "mainwindow.h"
#include <QApplication>
#include "butterfly.h"
#include <QGraphicsScene>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene *scene = new QGraphicsScene;
    scene->setSceneRect(QRectF(-682,-383,1364,766));

    Butterfly *butterfly = new Butterfly;
    butterfly->setPos(0,0);

    scene->addItem(butterfly);

    QGraphicsView *view = new QGraphicsView;
    view->setScene(scene);
    view->resize(1366,768);
    view->showFullScreen();

    return a.exec();
}
