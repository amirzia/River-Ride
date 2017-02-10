
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QList>

#include "Engine.h"
#include "Enemy.h"
#include <typeinfo>


extern Engine * engine;

int Enemy::getValue() { return value; }

Enemy::Enemy(int speed, QGraphicsItem *parent, int type): QObject(), QGraphicsPixmapItem(parent){
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

    this->speed = speed;
    //set random x position
    int random_number = rand() % (400 - pixmap().width()) + 200;
    setPos(random_number, 0);

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(speed);
}

int Enemy::getScore() {
    switch (type) {
        case 0:
            return 100;
            break;
        case 1:
            return 60;
            break;
        case 2:
            return 60;
            break;
        case 3:
            return 30;
            break;
        case 4:
            return 150;
        break;
    };
}

void Enemy::move(){
    // move enemy down
    setPos(x(),y()+5);

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)) {;
            if (type == 4) {
                engine->fuel->addFuel();
            } else {
                engine->fuel->collide();
            }

            scene()->removeItem(this);
            delete this;
        }
    }

    // destroy enemy when it goes out of the screen
    if (pos().y() > 600){
//        decrease the health
//        engine->health->decrease();

        scene()->removeItem(this);
        delete this;
        qDebug() << "enemy went out of screen and removed!";
    }
}
