#include "attaquewindow.h"
#include "ui_attaquewindow.h"

AttaqueWindow::AttaqueWindow(QWidget *parent, Game* game):
    QDialog (parent),
    ui(new Ui::AttaqueWindow())
{
    ui->setupUi(this);
    this->game = game;
    this->attaqueSelected = false;

}



void AttaqueWindow::on_AttaqueButton_accepted()
{
    this->attaqueSelected = true;
    this->game->setAttaqueMode(this->attaqueSelected);
    this->close();

}

void AttaqueWindow::on_AttaqueButton_rejected()
{
    this->attaqueSelected = false;
    this->game->setAttaqueMode(this->attaqueSelected);
    this->close();
}


