#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>
#include <QMouseEvent>
#include <QDebug> // bon pour les qpoint + mieux que cout
#include <QString>
#include <QPixmap>
#include <QWidget>
#include <QDesktopWidget>
#include <QMainWindow>

MainWindow::MainWindow(Game* game, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{

    this->game = game;


        std::cout << "supergame->getCellType(0,0)" << std::endl;
    std::cout << this->game->getCellType(0,0) << std::endl;
        std::cout << "supergame->getCellType(0,0)" << std::endl;
    ui->setupUi(this);
    connect(&timer, SIGNAL(timeout()),this,SLOT(tick()));
    dicoQPixMap = this->creationDicoQPixMap();

    //resize(QDesktopWidget().availableGeometry(this).size() * 0.7);

    QDesktopWidget dw;
    this->xDesktop =dw.height()*0.7;
    this->yDesktop=dw.height()*0.7;
    setFixedSize(this->xDesktop,this->yDesktop);
    //timer.start(10);

}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){

    QPainter painter(this);
    //std::map<string, QPixmap > dicoQPixMap = this->creationDicoQPixMap(); Tres mauvaise idée car prend beaucoup de temps
    std::string type; //pointeur
    // lire le vector vector et dessiner son qsas'écontenu
    // Remplacer 10 par variable size
    int xSizeBlock = xDesktop/17;
    int ySizeBlock = yDesktop/21;
    for (int i=0; i<17; i++){
        for(int j=0; j<21; j++){
            std::cout << "call cell " << this->game->getColums() <<std::endl;
            type = this->game->getCellType(i,j);
            std::cout << "*******getcelltype "<< this->game << std::endl;
            painter.drawPixmap(xSizeBlock *i,ySizeBlock *j,xSizeBlock ,ySizeBlock ,dicoQPixMap[type]);
            std::cout << "testa" << std::endl;

            }

        }

}



void MainWindow::mousePressEvent(QMouseEvent *event){
    std:: cout << event->x()<<"," << event->y()<< std:: endl;
    qDebug()<< event->pos();
    //this->game->calculer_cellule(event->x(), event->y());
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
    dicoQPixMap.insert({"plain", QPixmap(":/terrain/Resources/plain.png")});
    dicoQPixMap.insert({"mountain", QPixmap(":/terrain/Resources/mountain.png")});
    dicoQPixMap.insert({"wood",QPixmap(":/terrain/Resources/wood.png")});
    dicoQPixMap.insert({"hpipe", QPixmap(":/terrain/Resources/hpipe.png")});
    dicoQPixMap.insert({"river", QPixmap(":/terrain/Resources/river.png")});
    dicoQPixMap.insert({"greenearthcity", QPixmap(":/terrain/Resources/greenearthcity.png")});
    dicoQPixMap.insert({"hroad",QPixmap(":/terrain/Resources/hroad.png")});
    dicoQPixMap.insert({"reef",QPixmap(":/terrain/Resources/reef.png")});
    dicoQPixMap.insert({"greenearthairport",QPixmap(":/terrain/Resources/greenearthairport.png")});
    dicoQPixMap.insert({"greenearthbase",QPixmap(":/terrain/Resources/greenearthbase.png")});
    return dicoQPixMap;
}


void MainWindow::resizeEvent (QResizeEvent *event)
{
// My signal
emit iconSizeChanged(event->size());
}




                 //painter.drawRect(50, 100, 20, 40);
                 //painter.fillRect(50+a, 100, 20, 40, Qt::red);
                 //painter.save();
                 //painter.translate(100,0);
                 //painter.fillRect(50,100, 20, 48, Qt::red);
                 //painter.fillRect(50,150, 20, 48, Qt::red);
                 //painter.restore();
                 //painter.fillRect(50, 100, 10, 20, Qt::blue);
