
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>
#include <tree.h>
#include <stdlib.h>
#include <QDebug>

#include "Enemy.h"
#include "Engine.h"

Engine::Engine(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    score = new Score();
    scene->addItem(score);

    // create the player
    player = new Player();
    player->setPixmap(QPixmap(":/images/player.png"));
    player->setPos(scene->width()/2 - player->pixmap().width(), scene->height() - player->pixmap().height());
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    setBackgroundBrush(QBrush(QImage(":/images/bg.png")));


    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(createEnemy()));
    timer->start(2000);

    QTimer *timer2 = new QTimer();
    QObject::connect(timer2, SIGNAL(timeout()), player, SLOT(createTree()));
    timer2->start(3000);

    show();
}
