//#include "Player.h"
//#include <Bullet.h>
//#include <QGraphicsScene>
//#include <Enemy.h>
//#include <QGraphicsScene>
//#include <QKeyEvent>
//#include <Enemy.h>



//Player::Player(QGraphicsItem * parent):QGraphicsRectItem(parent){
////    setPixmap(QPixmap(":img/F22-Jet-300px.png"));
//    bulletSound = new QMediaPlayer;
//    bulletSound->setMedia(QUrl("qrc:/sounds/sounds/gunshot/166191__shawnyboy__gunshot-4.wav"));
//    bulletSound->setVolume(100);


////    enemyCreateTimer = new QTimer(this);
////    connect(enemyCreateTimer, SIGNAL(timeout()), this, SLOT(createEnemy()));
////    enemyCreateTimer->start(2000);
//}


//void Player::keyPressEvent(QKeyEvent *event){
//    if(event->key() == Qt::Key_Right && x() + 100 < 800){
//        setPos(x() + 10, y());
//    }
//    else if(event->key() == Qt::Key_Left && x() > 0){
//        setPos(x() - 10, y());
//    }
//    else if(event->key() == Qt::Key_Space){
//        Bullet * bullet = new Bullet();
//        bullet->setPos(x(), y());
//        qDebug() << "bullet created!";
//        scene()->addItem(bullet);

//        // play shot sound
//        if (bulletSound->state() == QMediaPlayer::PlayingState){
//            bulletSound->setPosition(0);
//        }
//        else if (bulletSound->state() == QMediaPlayer::StoppedState){
//            bulletSound->play();
//        }
//    }

//}


//void Player::createEnemy(){
//    Enemy * enemy = new Enemy();
//    scene()->addItem(enemy);
//}


#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsRectItem(parent){
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sounds/sounds/gunshot.wav"));
    bulletSound->setVolume(50);
}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

        // play bulletsound
        if (bulletSound->state() == QMediaPlayer::PlayingState){
            bulletSound->setPosition(0);
        }
        else if (bulletSound->state() == QMediaPlayer::StoppedState){
            bulletSound->play();
        }

    }
}

void Player::createEnemy(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
