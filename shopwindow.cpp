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
    this->game->buy("Infantry", this->cellule);
    this->close();
}

void ShopWindow::on_reconPushButton_Recon_clicked()
{
    this->game->buy("Recon", this->cellule);
    this->close();
}

void ShopWindow::on_pushButton_TankM_clicked()
{
    this->game->buy("TankM", this->cellule );
    this->close();
}

void ShopWindow::on_pushButton_Tank_clicked()
{
    this->game->buy("Tank", this->cellule);
    this->close();
}

void ShopWindow::on_pushButton_NeoTank_clicked()
{
    this->game->buy("NeoTank", this->cellule);
    this->close();
}

void ShopWindow::on_pushButton_MegaTank_clicked()
{
    this->game->buy("MegaTank", this->cellule);
    this->close();
}


void ShopWindow::on_pushButton_Fighter_clicked()
{
    this->game->buy("Fighter", this->cellule);
    this->close();
}

void ShopWindow::on_pushButton_Bomber_clicked()
{
    this->game->buy("Bomber", this->cellule);
    this->close();
}

void ShopWindow::on_pushButton_BCopter_clicked()
{
    this->game->buy("BCopter", this->cellule);
    this->close();
}

void ShopWindow::on_pushButton_AntiAir_clicked()
{
    this->game->buy("AntiAir", this->cellule);
    this->close();
}

void ShopWindow::on_pushButton_Bazooka_clicked()
{
    this->game->buy("Bazooka", this->cellule);
    this->close();
}




