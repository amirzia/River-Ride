#ifndef TREE_H
#define TREE_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

class Tree:public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Tree(QGraphicsItem * parent=0);
public slots:
    void moveDown();
};

#endif // TREE_H
