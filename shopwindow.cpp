#include "shopwindow.h"
#include "ui_shopwindow.h"

ShopWindow::ShopWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShopWindow)
{
    ui->setupUi(this);


}

ShopWindow::~ShopWindow()
{
    delete ui;
}

void ShopWindow::on_pushButton_clicked()
{

}
