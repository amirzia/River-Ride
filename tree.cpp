#include "tree.h"
#include <QGraphicsScene>
#include <QDebug>


Tree::Tree(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/tree.png"));
}

void Tree::moveDown() {
    setPos(x(), y() + 5);
    if (y() >= 600) {
        scene()->removeItem(this);
        delete this;
        qDebug() << "one new tree is removed.";
    }
}
