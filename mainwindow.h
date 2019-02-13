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

    void keyPressEvent(QKeyEvent* event);
    void resizeEvent(QResizeEvent *event);

public slots:
    void tick();
private:
    int xDesktop;
    int yDesktop;


    Game* game = nullptr;
    Ui::MainWindow *ui;
    QTimer timer;
    int a=5;
    std::map<std::string, QPixmap> dicoQPixMap;
};

#endif // MAINWINDOW_Hs
