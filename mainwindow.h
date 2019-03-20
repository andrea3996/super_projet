#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

#include <QMainWindow>
#include <QTimer>
#include <QPixmap>
#include <QLabel>
#include <vector>
#include <string>

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>


#include "game.h"
#include "shopwindow.h"


using std::string;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Game* bla, QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event); // cliquer
    //tracers
    std::map<string, QPixmap> creationDicoQPixMap();
    std::map<string, QPixmap> creationDicoQPixUnit();

    void keyPressEvent(QKeyEvent* event);
    void resizeEvent(QResizeEvent *event);

    void openShopWindow(Cellule* cellule);

    void paintEventBuilding(std::string a, int i, int j);


public:
    Game* game = nullptr;

public slots:
    void tick();

private:
    int xDesktop;
    int yDesktop;

    Ui::MainWindow *ui;
    QTimer timer;
    int a=5;
    std::map<std::string, QPixmap> dicoQPixMap;
    std::map<std::string, QPixmap> dicoQPixUnit;
    bool terrain;
    bool shopWindow;

    ShopWindow *shopwindow;
    int xCursor = 0;
    int yCursor  = 0;
};

#endif // MAINWINDOW_Hs
