//#ifndef PLAYER_H
//#define PLAYER_H

//#include <QGraphicsRectItem>
//#include <QGraphicsItem>
//#include <QObject>
//#include <QMediaPlayer>

//class Player : public QObject,public QGraphicsRectItem{
//    Q_OBJECT
//public:
//    Player(QGraphicsItem * parent = 0);

//    void keyPressEvent(QKeyEvent * event);
//private:
//    QMediaPlayer * bulletSound;
//    QTimer * enemyCreateTimer;


//public slots:
//    void createEnemy();
//};


//#endif // PLAYER_H


#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Player:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void createEnemy();
private:
    QMediaPlayer * bulletSound;
};

#endif // PLAYER_H
