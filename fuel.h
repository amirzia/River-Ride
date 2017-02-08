#ifndef FUEL_H
#define FUEL_H

#include <QGraphicsTextItem>
#include <QObject>

class Fuel: public QGraphicsTextItem {
    Q_OBJECT
    int value;
public:
    Fuel();
    void addFuel();
public slots:
    void decrease();
    void collide();
};

#endif // FUEL_H
