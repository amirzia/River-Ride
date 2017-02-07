
#include <QTimer>
#include <QGraphicsScene>
#include <typeinfo>
#include <QDebug>
#include <QString>
#include <QList>

#include "Enemy.h"
#include "Engine.h"
#include "Bullet.h"

extern Engine * engine; // there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem (parent){
    // drew the bullet (a rectangle)
    setPixmap(QPixmap(":/images/bullet.png"));

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
    if (pos().y() + pixmap().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
