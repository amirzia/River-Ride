//#ifndef ENGINE_H
//#define ENGINE_H

//#include <QWidget>
//#include "Player.h"
//#include <QGraphicsScene>
//#include <QGraphicsView>


//class Engine: public QGraphicsView{

//public:
//    Engine(QWidget * parent = 0);

//    Player * player;
//    QGraphicsScene * scene;


////private:
////    QTimer * timer;

//};


//#endif // ENGINE_H


#ifndef ENGINE_H
#define ENGINE_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
//#include "Score.h"
//#include "Health.h"

class Engine: public QGraphicsView{
public:
    Engine(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
//    Score * score;
//    Health * health;

};

#endif // ENGINE_H
