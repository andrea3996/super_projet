#include "mainwindow.h"
#include <QApplication>


#include <QtWidgets>


int main(int argc, char *argv[])
{

    Game game;

    QApplication a(argc, argv);
    MainWindow w;
    w.setGame(game);
    w.show();

    return a.exec();
}
