
#include <QApplication>

#include "Engine.h"

Engine * engine;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    engine = new Engine();
    engine->show();

    return a.exec();
}
