
#ifndef ENGINE_H
#define ENGINE_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"

class Engine: public QGraphicsView{
public:
    Engine(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
//    Score * score;
//    Health * health;

};

#endif // ENGINE_H
