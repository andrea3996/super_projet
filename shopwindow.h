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
    void on_pushButton_clicked();

private:
    Ui::ShopWindow *ui;
};

#endif // SHOPWINDOW_H
