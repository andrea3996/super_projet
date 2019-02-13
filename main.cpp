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
    std::cout << "initialisation du game " << supergame->getCellType(0,0) << std::endl;
    //cout << "test cas qui fonctionne " <<supergame->calculer_cellule(30*3, 30*10 ).first << " " << supergame->calculer_cellule(30*3, 30*10).second<< endl;


    MainWindow w(supergame);
    std::cout << "initialisation du game " << supergame->getCellType(0,0) << std::endl;
    w.show();
    //delete supergame //TODO
    return a.exec();

}

