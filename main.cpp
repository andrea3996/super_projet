#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets>
#include "game.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Game * supergame = new Game();
    MainWindow w(supergame);
    w.show();
    return a.exec();

}

