#include "shopwindow.h"
#include "ui_shopwindow.h"

ShopWindow::ShopWindow(QWidget *parent) :
    // Building
    QDialog(parent),
    ui(new Ui::ShopWindow)
{
    ui->setupUi(this);
    ui->infantryPushButton->setDefault(false);

}

ShopWindow::~ShopWindow()
{
    delete ui;
}

void ShopWindow::on_infantryPushButton_clicked()
{
    // TODO : acheter une infanterie
}

void ShopWindow::on_reconPushButton_clicked()
{
    //buy etc

}

void ShopWindow::on_pushButton_TankM_clicked()
{

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

void ShopWindow::on_pushButton_clicked()
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
