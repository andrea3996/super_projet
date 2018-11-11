#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets>

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Game supergame; // l'erreur n'est pas dans Game

    QApplication a(argc, argv);
    MainWindow w(&supergame);
    w.show();

    //std::pair<int,int> test = game.calculer_cellule(3,3);

    return 1;
}
