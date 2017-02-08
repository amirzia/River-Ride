#include "fuel.h"
#include <QFont>

Fuel::Fuel() {
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
    setPlainText(QString("Fuel: 100/100"));
    value = 100;
}

void Fuel::addFuel() {
    value += 20;
    if (value >= 100) {
        value = 100;
        setPlainText(QString("Fuel: 100/100"));
    } else {
        setPlainText(QString("Fuel: " + QString::number(value) + "/100"));
    }
}

void Fuel::decrease() {
    value -= 1;
    if (value <= 0) {
        setPlainText(QString("Fuel: 0/100"));
    } else {
        setPlainText(QString("Fuel: " + QString::number(value) + "/100"));
    }
}

void Fuel::collide() {
    value -= 10;
    if (value <= 0) {
        setPlainText(QString("Fuel: 0/100"));
    } else {
        setPlainText(QString("Fuel: " + QString::number(value) + "/100"));
    }
}
