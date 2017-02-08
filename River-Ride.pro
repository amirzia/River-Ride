#-------------------------------------------------
#
# Project created by QtCreator 2017-02-06T11:13:46
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = River-Ride
TEMPLATE = app


SOURCES += main.cpp \
    Engine.cpp \
    Bullet.cpp \
    Player.cpp \
    Enemy.cpp \
    tree.cpp

HEADERS  += \
    Bullet.h \
    Enemy.h \
    Player.h \
    Engine.h \
    tree.h

FORMS    +=

RESOURCES += \
    res.qrc
