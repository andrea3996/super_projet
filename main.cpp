#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets>
#include "cellule.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Game supergame; // l'erreur n'est pas dans Game

    QApplication a(argc, argv);
    MainWindow w(&supergame);
    w.show();

    //std::pair<int,int> test = game.calculer_cellule(3,3);
    std:: cout << "Hello" << std:: endl;

    std::string tp = "plain";
    Cellule unobjet = Cellule(tp);
    return a.exec();
    std :: cout << unobjet.m["plain"]


}



//std:: cout << liste << std:: endl;

//qDebug()<<liste;


