
#include <QGraphicsScene>
#include <QKeyEvent>
#include <stdlib.h>
#include <QDebug>
#include <QTimer>

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "tree.h"
#include <QMediaPlayer>
#include <Bridge.h>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sounds/sounds/gunshot.wav"));
    bulletSound->setVolume(50);

    enemySpeed = 50;

    QTimer * levelTimer = new QTimer(this);
    connect(levelTimer, SIGNAL(timeout()), this, SLOT(increaseLevel()));
    levelTimer->start(20000);

    level = 1;
    qDebug() << "The game started in level one.";
}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 200)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + pixmap().width() < 600)
        setPos(x()+10,y());
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x() + pixmap().width()/2 - bullet->pixmap().width()/2,y());
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
    int type = rand() % 5;
    Enemy * enemy = new Enemy(enemySpeed, 0 ,type);
    scene()->addItem(enemy);
    qDebug() << "one new enemy is created!";
}


void Player::createBridge(){
    if(level < 5){
        qDebug() << "one new bridge is created";
        Bridge * bridge = new Bridge();
        scene()->addItem(bridge);

        QTimer * timer = new QTimer();
        QObject::connect(timer, SIGNAL(timeout()), bridge, SLOT(moveDown()));
        timer->start(50);
    }
}


void Player::createTree() {
    qDebug() << "one new tree is created.";
    Tree *tree = new Tree();
    int pos = (rand() % (200 - tree->pixmap().width())) + (rand() % 2) * 600;
    scene()->addItem(tree);
    tree->setPos(pos, 20);

    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), tree, SLOT(moveDown()));
    timer->start(50);
}

void Player::increaseLevel(){
    if(enemySpeed == 50){
        qDebug() << "Game Level Speed is set to 40";
        enemySpeed = 40;
    }
    else if(enemySpeed == 40){
        enemySpeed = 30;
        qDebug() << "Game Level Speed is set to 30";
    }
    else if(enemySpeed == 30){
        enemySpeed = 25;
        qDebug() << "Game Level Speed is set to 25";
    }
    else if(enemySpeed == 25){
        enemySpeed = 15;
        qDebug() << "Game Level Speed is set to 15";
    }

    createBridge();
}
