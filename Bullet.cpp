//#include <Bullet.h>
//#include <Engine.h>
//#include <QGraphicsScene>
//#include <QTimer>
//#include <QObject>
//#include <QMediaPlayer>



//extern Engine * engine;



//Bullet::Bullet(QGraphicsItem * parent): QGraphicsRectItem(parent){
//    // make the bullet shape as a rectangle
//    setRect(0, 0, 10, 50);

//    // timer starts in order to move the bullet each 50 miliseconds
//    QTimer * timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
//    timer->start(50);



//}

//void Bullet::move(){
//    setPos(x(), y() - 10);

//}


#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include "Enemy.h"
#include "Engine.h"
#include <typeinfo>
#include <QDebug>
#include <QString>
#include <QList>

extern Engine * engine; // there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){
    // drew the bullet (a rectangle)
    setRect(0,0,10,50);

    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
     explosionSound = new QMediaPlayer();
     explosionSound->setMedia(QUrl("qrc:/sounds/sounds/Explosion.wav"));
     explosionSound->setVolume(100);
}
void Bullet::move(){
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){

            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete colliding_items[i];
            delete this;

            // play bulletsound
            if (explosionSound->state() == QMediaPlayer::PlayingState){
                explosionSound->setPosition(0);
            }
            else if (explosionSound->state() == QMediaPlayer::StoppedState){
                explosionSound->play();
            }

            // return (all code below refers to a non existint bullet)
            return;
        }
    }

    // if there was no collision with an Enemy, move the bullet forward
    setPos(x(),y()-10);
    // if the bullet is off the screen, destroy it
    if (pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
