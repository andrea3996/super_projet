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
    ui->setupUi(this);
    connect(&timer, SIGNAL(timeout()),this,SLOT(tick()));
    dicoQPixMap = this->creationDicoQPixMap();
    dicoQPixUnit = this->creationDicoQPixUnit();
    //resize(QDesktopWidget().availableGeometry(this).size() * 0.7);

    QDesktopWidget dw;

    setFixedSize(game->getTailleCellule()*game->getColums(), game->getTailleCellule()*game->getRows());
    terrain = true;
    shopWindow = false;
    //timer.start(10);

}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event) {

    QPainter painter(this);
    //std::map<string, QPixmap > dicoQPixMap = this->creationDicoQPixMap(); Tres maruvaise idée car prend beaucoup de temps
    std::string type=""; //pointeur
    std::string unitType="";
    std::vector<int> value;

    for (int i=0; i<game->getRows(); i++){ // i= rows=17
        for(int j=0; j<game->getColums(); j++){ // j=column=21
            type = this->game->getCellType(i,j);
            unitType = this->game->getUnitType(i,j);
            /*if (unitType != "") {
                std::cout<< "Je ne suis pas"<< std::endl;
                painter.drawPixmap(game->getTailleCellule() *j,game->getTailleCellule() *i,game->getTailleCellule() ,game->getTailleCellule() ,dicoQPixUnit[unitType]);
            }else {*/
                std::cout<< "aaaaaa"<<unitType<<"bbbbbbbb"<< std::endl;
                painter.drawPixmap(game->getTailleCellule() *j,game->getTailleCellule() *i,game->getTailleCellule() ,game->getTailleCellule() ,dicoQPixMap[type]);
            //}


        }
    }
}


void MainWindow::mousePressEvent(QMouseEvent *event){
    std:: cout << event->x()<<"," << event->y()<< std:: endl;
    qDebug()<< event->pos();
    // si terrain afficher
    this->game->calculer_cellule(event->y(), event->x());
    /*} else if(shopWindow == false){
        Building* building = this->game->getBuiling(event->x(), event->y());
        if ( this->game->getLp() == building->getOwner() && this->game->getMap()->getCell(building->getX(),building->getY()).getUnit() == nullptr){

            //openShopWindow
        }
        this->game->calculer_unit(event->x(), event->y());
   } else*/
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // savoir la touche qui à ete enfoncé (key)
    std:: cout << event->key()<< std:: endl;
}

void MainWindow::tick() {
    a++;
    update(); //appel paintEvent
}

std::map<string, QPixmap> MainWindow::creationDicoQPixMap(){
    std::map<string, QPixmap > dicoQPixMap;
    dicoQPixMap.insert({"plain", QPixmap(":/terrain/Resources/plain.png")});
    dicoQPixMap.insert({"mountain", QPixmap(":/terrain/Resources/mountain.png")});
    dicoQPixMap.insert({"wood",QPixmap(":/terrain/Resources/wood.png")});
    dicoQPixMap.insert({"hpipe", QPixmap(":/terrain/Resources/hpipe.png")});
    dicoQPixMap.insert({"river", QPixmap(":/terrain/Resources/hriver.png")});
    dicoQPixMap.insert({"hbridge", QPixmap(":/terrain/Resources/hbridge.png")});
    dicoQPixMap.insert({"city", QPixmap(":/terrain/Resources/neutralcity.png")});
    dicoQPixMap.insert({"hroad",QPixmap(":/terrain/Resources/hroad.png")});
    dicoQPixMap.insert({"reef",QPixmap(":/terrain/Resources/reef.png")});
    dicoQPixMap.insert({"airport",QPixmap(":/terrain/Resources/neutralairport.png")});
    dicoQPixMap.insert({"base",QPixmap(":/terrain/Resources/neutralbase.png")});
    dicoQPixMap.insert({"sea", QPixmap(":/terrain/Resources/sea.png")});
    dicoQPixMap.insert({"hshoal", QPixmap(":/terrain/Resources/hshoal.png")});
    return dicoQPixMap;
}

std::map<string, QPixmap> MainWindow::creationDicoQPixUnit(){
    std::map<string, QPixmap > dicoQPixUnit;
    dicoQPixUnit.insert({"AntiAir", QPixmap(":/unit/Resources/AntiAir.png")});
    dicoQPixUnit.insert({"BCopter", QPixmap(":/unit/Resources/BCopter.png")});
    dicoQPixUnit.insert({"Bomber", QPixmap(":/unit/Resources/Bomber.png")});
    dicoQPixUnit.insert({"Fighter", QPixmap(":/unit/Resources/Fighter.png")});
    dicoQPixUnit.insert({"Infantery", QPixmap(":/unit/Resources/Infantery.png")});
    dicoQPixUnit.insert({"MegaTank", QPixmap(":/unit/Resources/MegaTank.png")});
    dicoQPixUnit.insert({"NeoTank", QPixmap(":/unit/Resources/NeoTank.png")});
    dicoQPixUnit.insert({"Recon", QPixmap(":/unit/Resources/Recon.png")});
    dicoQPixUnit.insert({"TankM", QPixmap(":/unit/Resources/TankM.png")});

    return dicoQPixUnit;

}
void MainWindow::resizeEvent (QResizeEvent *event)
{
    // My signal
    emit iconSizeChanged(event->size());
}

void MainWindow::openShopWindow(Cellule* cellule)
{
    ShopWindow shopWindow(nullptr, cellule, this->game); // variable de classe (this->)
    shopWindow.setModal(true);
    shopWindow.exec();
}
