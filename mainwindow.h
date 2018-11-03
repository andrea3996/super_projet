#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <game.h>
#include <iostream>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event); // cliquer
    //tracer
    void mouseMoveEvent(QMouseEvent * event);

    void keyPressEvent(QKeyEvent* event);
    void setGame(Game& g); // pointe vers l'adresse de g

public slots:
    void tick();
private:

    Game* game;
    Ui::MainWindow *ui;
    QTimer timer;
    int a=5;
    int taille_cellule = 30;
};

#endif // MAINWINDOW_Hs
