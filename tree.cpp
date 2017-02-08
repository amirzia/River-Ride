#include "tree.h"
#include <QGraphicsScene>

Tree::Tree(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/tree.png"));
}

void Tree::moveDown() {
    setPos(x(), y() + 5);
    if (y() >= 600) {
        scene()->removeItem(this);
        delete this;
    }
}
