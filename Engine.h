
#ifndef ENGINE_H
#define ENGINE_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "score.h"
#include "fuel.h"

class Engine: public QGraphicsView{
public:
    Engine(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Fuel * fuel;

public slots:
    void createTree();
};

#endif // ENGINE_H
