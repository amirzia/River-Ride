//#ifndef ENEMY_H
//#define ENEMY_H

//#include <Enemy.h>
//#include <stdlib.h>
//#include <QGraphicsRectItem>

//class Enemy: public QObject, QGraphicsRectItem{
//    Q_OBJECT
//public:
//    Enemy(QGraphicsItem * parent=0);
////private:

//public slots:
//    void move();
//};


//#endif // ENEMY_H


#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // ENEMY_H
