//#include <Engine.h>
//#include <QTimer>
//#include "Enemy.h"


//Engine::Engine(QWidget * parent){


//    // make scene and show that
//    scene = new QGraphicsScene();
//    setSceneRect(0, 0, 800, 600);
//    setScene(scene);

//    // initialize the size of game display
//    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    setFixedSize(800, 600);


//    // make the player, set its position
//    player = new Player();
//    // make focus on the player
//    player->setFlag(QGraphicsItem::ItemIsFocusable);
//    player->setFocus();

//    player->setRect(0, 0, 100, 100);
//    player->setPos(width()/2, height() + 19);


//    scene->addItem(player);




//    QTimer * timer = new QTimer();
//    connect(timer, SIGNAL(timeout()), player, SLOT(createEnemy()));
//    timer->start(1000);


//    show();
//}

#include "Engine.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QMediaPlayer>

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

    // create the player
    player = new Player();
    player->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);


    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(createEnemy()));
    timer->start(2000);


    show();
}
