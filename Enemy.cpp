
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include <QGraphicsPixmapItem>
#include <QPixmap>

#include "Engine.h"
#include "Enemy.h"

extern Engine * engine;

int Enemy::getValue() { return value; }

Enemy::Enemy(QGraphicsItem *parent, int type): QObject(), QGraphicsPixmapItem(parent){
    this->type = type;
    switch (type) {
        case 0:
            setPixmap(QPixmap(":images/jet.png"));
            break;
        case 1:
            setPixmap(QPixmap(":images/ballon.png"));
            break;
        case 2:
            setPixmap(QPixmap(":images/heli.png"));
            break;
        case 3:
            setPixmap(QPixmap(":images/naftkesh.png"));
            break;
        case 4:
            setPixmap(QPixmap(":images/fuel.png"));
            break;
    }

    //set random x position
    int random_number = rand() % (400 - pixmap().width()) + 200;
    setPos(random_number, 0);

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Enemy::move(){
    // move enemy down
    setPos(x(),y()+5);

    // destroy enemy when it goes out of the screen
    if (pos().y() > 600){
//        decrease the health
//        engine->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
