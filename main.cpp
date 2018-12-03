#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets>
#include "game.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game * supergame = new Game(); // lire de droite à gauche !

    cout << "test < 0 pour x "<<supergame->calculer_cellule(-15*30, 100).first << " " << supergame->calculer_cellule(-15*30,100).second << endl;
    cout << " test < 0 pour y" <<supergame->calculer_cellule(100, -15*30).first << " " << supergame->calculer_cellule(100,-15*30).second << endl;
    cout << "test > column   (x) " <<supergame->calculer_cellule(30*21, 100).first << " " << supergame->calculer_cellule(30*21, 100).second << endl;
    cout << "test < row    (y) " <<supergame->calculer_cellule(100, 30*17 ).first << " " << supergame->calculer_cellule(100, 30*17).second << endl;


    MainWindow w(supergame);
    w.show();
    delete supergame;
    return a.exec();

}

