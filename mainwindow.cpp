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


    QPainter painter(this);
    std::map<string, QPixmap > dicoQPixMap = this->creationDicoQPixMap();
    std::string type;
    QPixmap qpm;
    int i, j;
    // lire le vector vector et dessiner son qsas'écontenu
    for (i=0; i<21;i++){
        for(j=0; j<17;j++){
            std:: cout << "-----------------" << std::endl;
            std:: cout << this->game << std::endl;
            type = this->game->getCellType(i,j);
            std:: cout << "-----------------" << std::endl;
            qpm = dicoQPixMap[type];
            std:: cout << "000000000000000000" << std::endl;
            painter.drawPixmap(i*21,j*21,21,21,qpm);
            std:: cout << "&&&&&&&&&&&&&&&&&&&" << std::endl;


        }
    }

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
