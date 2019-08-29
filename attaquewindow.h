#ifndef ATTAQUEWINDOW_H
#define ATTAQUEWINDOW_H

#include <QDialog>
#include "game.h"



namespace Ui {
class AttaqueWindow;
}

class AttaqueWindow : public QDialog
{
    Q_OBJECT
public:
    explicit AttaqueWindow(QWidget *parent = nullptr, Game* game= nullptr );
     //~AttaqueWindow();

private slots:
    void on_AttaqueButton_accepted();

    void on_AttaqueButton_rejected();

private:
    bool attaqueSelected;
    Ui::AttaqueWindow *ui;
    Game* game;
};

#endif // ATTAQUEWINDOW_H
