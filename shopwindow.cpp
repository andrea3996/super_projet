#include "shopwindow.h"
#include "ui_shopwindow.h"
#include "game.h"

ShopWindow::ShopWindow(QWidget *parent, Cellule *cellule, Game* game) :

    QDialog(parent),
    ui(new Ui::ShopWindow)
{
    ui->setupUi(this);
    ui->infantryPushButton->setDefault(false);
    this->cellule = cellule;
    this->game = game;
}

ShopWindow::~ShopWindow()
{
    delete ui;
}

void ShopWindow::on_infantryPushButton_clicked()
{

    this->game->buy("infantry", this->cellule);


}



void ShopWindow::on_pushButton_TankM_clicked()
{
    this->game->buy("TankM", this->cellule );

}

void ShopWindow::on_pushButton_Tank_clicked()
{

}

void ShopWindow::on_pushButton_NeoTank_clicked()
{

}

void ShopWindow::on_pushButton_MegaTank_clicked()
{

}


void ShopWindow::on_pushButton_Fighter_clicked()
{

}

void ShopWindow::on_pushButton_Bomber_clicked()
{

}

void ShopWindow::on_pushButton_BCopter_clicked()
{

}

void ShopWindow::on_pushButton_AntiAir_clicked()
{

}

void ShopWindow::on_pushButton_Bazooka_clicked()
{

}
