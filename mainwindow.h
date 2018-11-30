#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

#include <QMainWindow>
#include <QTimer>

#include "game.h"

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

    void keyPressEvent(QKeyEvent* event);

public slots:
    void tick();
private:

    Game* game = nullptr;
    Ui::MainWindow *ui;
    QTimer timer;
    int a=5;
};

#endif // MAINWINDOW_Hs
