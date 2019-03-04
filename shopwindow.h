#ifndef SHOPWINDOW_H
#define SHOPWINDOW_H

#include <QDialog>

namespace Ui {
class ShopWindow;
}

class ShopWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ShopWindow(QWidget *parent = nullptr);
    ~ShopWindow();

private slots:
    //void on_pushButton_clicked();

    void on_reconPushButton_clicked();

    void on_infantryPushButton_clicked();

    //void on_listView_objectNameChanged(const QString &objectName);

    void on_pushButton_clicked();

    void on_pushButton_TankM_clicked();

    void on_pushButton_Tank_clicked();

    void on_pushButton_NeoTank_clicked();

    void on_pushButton_MegaTank_clicked();

    void on_pushButton_Fighter_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_Bomber_clicked();

    void on_pushButton_BCopter_clicked();

    void on_pushButton_AntiAir_clicked();

    void on_pushButton_Bazooka_clicked();

private:
    Ui::ShopWindow *ui;
};

#endif // SHOPWINDOW_H
