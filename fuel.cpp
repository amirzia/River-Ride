#include "fuel.h"
#include <QFont>
#include <QMutex>
#include <windows.h>
#include <QDebug>

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
        setPlainText(QString("The fuel is finished!!! YOU LOST THE GAME!!!"));
//        QMutex mut;
//        mut.lock();
//        mut.tryLock(200000);
        Sleep(20000);
    } else {
        setPlainText(QString("Fuel: " + QString::number(value) + "/100"));
    }
}

void Fuel::collide() {
    value -= 10;
    qDebug() << "One object collided and the fuel decreased 10 units.";
    if (value <= 0) {
        setPlainText(QString("Fuel: 0/100"));
    } else {
        setPlainText(QString("Fuel: " + QString::number(value) + "/100"));
    }
}
