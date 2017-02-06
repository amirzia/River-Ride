//#include <Player.h>
//#include <QApplication>
//#include <QGraphicsScene>
//#include <QGraphicsView>
//#include <Engine.h>


//Engine * engine;
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);

//    engine = new Engine();

////    Engine * engine = new Engine();



//    return a.exec();
//}


#include <QApplication>
#include "Engine.h"

/*
Tutorial Topics:
-resource files
-QMediaPlayer, setMedia(), QUrl, play()
*/

Engine * engine;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    engine = new Engine();
    engine->show();

    return a.exec();
}
