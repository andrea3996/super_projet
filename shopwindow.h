#ifndef SHOPWINDOW_H
#define SHOPWINDOW_H

#include <QDialog>
#include "building.h"


namespace Ui {
class ShopWindow;
}

class ShopWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ShopWindow(QWidget *parent = nullptr, Building *building() );
    ~ShopWindow();

private slots:

    void on_reconPushButton_clicked();

    void on_infantryPushButton_clicked();

    void on_pushButton_TankM_clicked();

    void on_pushButton_Tank_clicked();

    void on_pushButton_NeoTank_clicked();

    void on_pushButton_MegaTank_clicked();

    void on_pushButton_Fighter_clicked();

    void on_pushButton_Bomber_clicked();

    void on_pushButton_BCopter_clicked();

    void on_pushButton_AntiAir_clicked();

    void on_pushButton_Bazooka_clicked();

private:
    Ui::ShopWindow *ui;
    //Building* building;
};

#endif // SHOPWINDOW_H
