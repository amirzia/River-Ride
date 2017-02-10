
#include <QGraphicsScene>
#include <Bridge.h>
#include <QDebug>
Bridge::Bridge(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/Bridge.JPG"));
}

void Bridge::moveDown() {
    setPos(x(), y() + 5);
    if (y() >= 600) {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bridge removed!";
    }
}


