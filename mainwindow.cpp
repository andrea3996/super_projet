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
    std::cout << "paint event called" << std::endl;
    QPainter painter(this);
    //std::map<string, QPixmap > dicoQPixMap = this->creationDicoQPixMap(); Tres maruvaise idée car prend beaucoup de temps
    std::string type=""; //pointeur
    std::string unitType= "";
    std::vector<int> value;

    for (int i=0; i<game->getRows(); i++){ // i= rows=17
        for(int j=0; j<game->getColums(); j++){ // j=column=21
            type = this->game->getCellType(i,j);
            unitType = this->game->getUnitType(i,j);
            if (unitType != "") {
                //painter.drawPixmap(game->getTailleCellule() *j,game->getTailleCellule() *i,game->getTailleCellule() ,game->getTailleCellule() ,dicoQPixMap[type]);
                std::cout << unitType << std::endl;
                painter.drawPixmap(game->getTailleCellule() *j,game->getTailleCellule() *i,game->getTailleCellule() ,game->getTailleCellule() ,dicoQPixUnit[unitType]);
            }else {
                /* TODO
                //std::cout<< "aaaaaa "<<unitType<<" bbbbbbbb"<< std::endl;
                if (type=="city") {
                    if (this->game->getMap()->getCell(i, j)->getBuilding()->getOwner()->getTeamColor() == "orangestar") {

                    }
                    else if (this->game->getMap()->getCell(i, j)->getBuilding()->getOwner()->getTeamColor() == "greenearth") {

                    }

                } else if (type=="base") {
                    if (this->game->getMap()->getCell(i, j)->getBuilding()->getOwner()->getTeamColor() == "orangestar") {

                    }
                    else if (this->game->getMap()->getCell(i, j)->getBuilding()->getOwner()->getTeamColor() == "greenearth") {

                    }

                } else if (type=="airport") {
                    if (this->game->getMap()->getCell(i, j)->getBuilding()->getOwner()->getTeamColor() == "orangestar") {

                    }
                    else if (this->game->getMap()->getCell(i, j)->getBuilding()->getOwner()->getTeamColor() == "greenearth") {

                    }

                } else {
                }*/
                painter.drawPixmap(game->getTailleCellule() *j,game->getTailleCellule() *i,game->getTailleCellule() ,game->getTailleCellule() ,dicoQPixMap[type]);
            }
        }
    }
    std::cout << "paint event finished" << std::endl;
}


void MainWindow::mousePressEvent(QMouseEvent *event){
    std:: cout << event->x()<<"," << event->y()<< std:: endl;
    qDebug()<< event->pos();
    // si terrain afficher
    this->game->calculer_cellule(event->y(), event->x());

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // savoir la touche qui à ete enfoncé (key)
    //Possibilité curseur
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
    dicoQPixMap.insert({"greenearthbase", QPixmap(":/terrain/Resources/greenearthbase.png")});
    dicoQPixMap.insert({"greenearthairport", QPixmap(":/terrain/Resources/greenearthairport.png")});
    dicoQPixMap.insert({"greenearthcity", QPixmap(":/terrain/Resources/greenearthcity.png")});
    dicoQPixMap.insert({"orangestarcity", QPixmap(":/terrain/Resources/orangestarcity.png")});
    dicoQPixMap.insert({"orangestarairport", QPixmap(":/terrain/Resources/orangestarairport.png")});
    dicoQPixMap.insert({"orangestarbase", QPixmap(":/terrain/Resources/orangestarbase.png")});

    return dicoQPixMap;
}

std::map<string, QPixmap> MainWindow::creationDicoQPixUnit(){
    std::map<string, QPixmap > dicoQPixUnit;

    // GreenEarth Units
    dicoQPixUnit.insert({"AntiAir", QPixmap(":/unit/AntiAir.png")});
    dicoQPixUnit.insert({"BCopter", QPixmap(":/unit/BCopter.png")});
    dicoQPixUnit.insert({"Bomber", QPixmap(":/unit/Bomber.png")});
    dicoQPixUnit.insert({"Fighter", QPixmap(":/unit/Fighter.png")});
    dicoQPixUnit.insert({"Infantry", QPixmap(":/unit/Infantry.png")});
    dicoQPixUnit.insert({"MegaTank", QPixmap(":/unit/MegaTank.png")});
    dicoQPixUnit.insert({"NeoTank", QPixmap(":/unit/NeoTank.png")});
    dicoQPixUnit.insert({"Recon", QPixmap(":/unit/Recon.png")});
    dicoQPixUnit.insert({"TankM", QPixmap(":/unit/TankM.png")});

    //OrangeStar/ Red Units #ou trouver les bonnes images ?
    dicoQPixUnit.insert({"antiairR", QPixmap(":/unit/antiairR.png")});
    dicoQPixUnit.insert({"bcopter", QPixmap(":/unit/bcopterR.png")});
    dicoQPixUnit.insert({"bomberR", QPixmap(":/unit/bomberR.png")});
    dicoQPixUnit.insert({"fighterR", QPixmap(":/unit/fighterR.png")});
    dicoQPixUnit.insert({"osinfantry", QPixmap(":/unit/osinfantry.png")});
    dicoQPixUnit.insert({"megatankR", QPixmap(":/unit/megatankR.png")});
    dicoQPixUnit.insert({"neotankR", QPixmap(":/unit/neotankR.png")});
    dicoQPixUnit.insert({"reconR", QPixmap(":/unit/reconR.png")});
    dicoQPixUnit.insert({"tankR", QPixmap(":/unit/tankR.png")});


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
