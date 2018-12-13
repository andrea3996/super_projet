#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>
#include <QMouseEvent>
#include <QDebug> // bon pour les qpoint + mieux que cout
#include <QString>
#include <QPixmap>

MainWindow::MainWindow(Game* game, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->game = game;
    ui->setupUi(this);
    connect(&timer, SIGNAL(timeout()),this,SLOT(tick()));
    this->creationDicoQPixMap();

    //timer.start(10);

}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    //int a = 5;
    int pos_circle_x=8; //faire appel
    int pos_circle_y= 5;
    QPainter painter(this);
    std::map<string, QPixmap > dicoQPixMap = this->creationDicoQPixMap();
    std::string type;
    // lire le vector vector et dessiner son qsas'écontenu
    for (int i=0; i<10;i++){
        for(int j=0; j<10;j++){
            painter.fillRect(21*i, 21*j,20,20,Qt::red);
            if(i == pos_circle_x && j == pos_circle_y){  // better
                painter.drawEllipse(21*pos_circle_x, 21*pos_circle_y, 10, 10);
                type = this->game->getCellType(i,j);
                painter.drawPixmap(i,j,dicoQPixMap[type]);

            }

        }
    }
    //painter.drawPixmap(pix, x ,y)


}

void MainWindow::mousePressEvent(QMouseEvent *event){
    std:: cout << event->x()<<"," << event->y()<< std:: endl;
    qDebug()<< event->pos();
    this->game->calculer_cellule(event->x(), event->y());
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // savoir la touche qui à ete enfoncé (key)

    std:: cout << event->key()<< std:: endl;
}

void MainWindow::tick() {
    std:: cout << "hello " << a << std::endl;  // "hello": string mais 'h': char
    a++;
    update(); //appel paintEvent
}

std::map<string, QPixmap> MainWindow::creationDicoQPixMap(){
    std::map<string, QPixmap > dicoQPixMap;
    dicoQPixMap.insert({"plain", QPixmap(":/terrain/plain.png")});
    dicoQPixMap.insert({"mountain", QPixmap(":/terrain/mountain.png")});
    dicoQPixMap.insert({"wood",QPixmap(":/terrain/wood.png")});
    dicoQPixMap.insert({"hpipe", QPixmap(":/terrain/hpipe.png")});
    dicoQPixMap.insert({"river", QPixmap(":/terrain/river.png")});
    dicoQPixMap.insert({"greenearthcity", QPixmap(":/terrain/greenearthcity.png")});
    dicoQPixMap.insert({"hroad",QPixmap(":/terrain/hroad.png")});
    dicoQPixMap.insert({"reef",QPixmap(":/terrain/reef.png")});
    dicoQPixMap.insert({"greenearthairport",QPixmap(":/terrain/greenearthairport.png")});
    dicoQPixMap.insert({"greenearthbase",QPixmap(":/terrain/greenearthbase.png")});
    return dicoQPixMap;
}




                 //painter.drawRect(50, 100, 20, 40);
                 //painter.fillRect(50+a, 100, 20, 40, Qt::red);
                 //painter.save();
                 //painter.translate(100,0);
                 //painter.fillRect(50,100, 20, 48, Qt::red);
                 //painter.fillRect(50,150, 20, 48, Qt::red);
                 //painter.restore();
                 //painter.fillRect(50, 100, 10, 20, Qt::blue);
