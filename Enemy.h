
#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy: public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
private:
    int value;
    int type;
public:
    enum Type {
        jet = 0,
        ballon,
        heli,
        naftkesh,
        fuel_depot
    };

    int getValue();
    Enemy(QGraphicsItem * parent=0, int type = 0);
public slots:
    void move();
};

#endif // ENEMY_H
