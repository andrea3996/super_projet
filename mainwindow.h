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
    Game* game = nullptr;


public slots:
    void tick();
private:

    Ui::MainWindow *ui;
    QTimer timer;
    int a=5;
};

#endif // MAINWINDOW_Hs
