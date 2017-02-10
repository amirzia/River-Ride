
#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

class Player:public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void createEnemy();
    void createTree();
    void createBridge();

private:
    QMediaPlayer * bulletSound;
    int enemySpeed;
    int level;
public slots:
    void increaseLevel();
};

#endif // PLAYER_H
