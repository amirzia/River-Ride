#ifndef BRIDGE_H
#define BRIDGE_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

class Bridge:public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bridge(QGraphicsItem * parent=0);
public slots:
    void moveDown();
};



#endif // BRIDGE_H
