
#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include <QMediaPlayer>

class Bullet: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent=0);
private:
    QMediaPlayer * explosionSound;

public slots:
    void move();
};

#endif // BULLET_H
