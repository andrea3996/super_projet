#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>
#include <QMouseEvent>
#include <QDebug> // bon pour les qpoint + mieux que cout
#include <QString>
#include <QPixmap>
#include <QWidget>
#include <QPoint>
#include <QDesktopWidget>
#include <QMainWindow>
#include <map>


MainWindow::MainWindow(Game* game, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{

    this->game = game;
    ui->setupUi(this);
    connect(&timer, SIGNAL(timeout()),this,SLOT(tick()));
    dicoQPixMap = this->creationDicoQPixMap();
    dicoQPixUnit = this->creationDicoQPixUnit();
    tour = 0;
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


void MainWindow::drawCells(){

    QPainter painter(this);
    //std::map<string, QPixmap > dicoQPixMap = this->creationDicoQPixMap(); Tres maruvaise idée car prend beaucoup de temps
    std::string type=""; //pointeur
    std::string unitType= "";
    std::vector<int> value;
    std::string teamColor = "";
    std::string a = "";

    // x = j
    // y = i
    for (int i=0; i<game->getRows(); i++){ // i= rows=17
        for(int j=0; j<game->getColums(); j++){ // j=column=21
            type = this->game->getCellType(j,i);
            unitType = this->game->getUnitType(j,i);
            if (unitType != "") {
                painter.drawPixmap(game->getTailleCellule() *j,game->getTailleCellule() *i,game->getTailleCellule() ,game->getTailleCellule() ,dicoQPixUnit[unitType]);
            } else {
                if(this->game->getMap()->getCell(j, i)->getBuilding() != nullptr){

                    if (this->game->getMap()->getCell(j, i)->getBuilding()->getOwner() != nullptr){

                        teamColor = this->game->getMap()->getCell(j, i)->getBuilding()->getOwner()->getTeamColor();

                        if (type=="city") {
                            if (teamColor == "orangestar") {a = "orangestarcity";paintEventBuilding(a,j,i);}
                            else if (teamColor == "greenearth") {a= "greenearthcity";paintEventBuilding(a,j,i);}

                        } else if (type=="base") {
                            if (teamColor == "orangestar") {a="orangestarbase";paintEventBuilding(a,j,i);}

                            else if (teamColor == "greenearth") {a = "greenearthcity";paintEventBuilding(a,j,i);}

                        } else if (type=="airport") {
                            if (teamColor == "orangestar") {a= "orangestarairport";paintEventBuilding(a,j,i);}
                            else if (teamColor == "greenearth") {a = "greenearthairport";paintEventBuilding(a,j,i);}

                        }

                    }

                }
                painter.drawPixmap(game->getTailleCellule() *j,game->getTailleCellule() *i,game->getTailleCellule() ,game->getTailleCellule() ,dicoQPixMap[type]);
            }
        }
    }
}



void MainWindow::drawDestinationCells(){
    if(this->game != nullptr){
        Unit* sourceUnit = this->game->getUnitSelected();
        if(sourceUnit != nullptr){


            int max_y = game->getRows();
            int max_x = game->getColums();

            for(int x = 0; x < max_x; x++){
                for(int y = 0; y < max_y; y++){
                    Cellule* cell = this->game->getMap()->getCell(x, y);
                    cell->resetPointsRestants();
                }
            }

            int pointsActuels = 6; // points du jouer actif !

            int selected_cell_x = sourceUnit->get_x();
            int selected_cell_y = sourceUnit->get_y();
            int x_dest, y_dest;

            Cellule* source = game->getMap()->getCell(selected_cell_x, selected_cell_y);
            Cellule* celluleDestination;

            //evaluer vers le haut
            x_dest = selected_cell_x;
            y_dest = selected_cell_y - 1;
            celluleDestination = game->getMap()->getCellIfExists(x_dest, y_dest);
            if(celluleDestination != nullptr){
                game->getMap()->evaluerDeplacement(source, celluleDestination, pointsActuels);
            }

            //evaluer vers le bas
            x_dest = selected_cell_x;
            y_dest = selected_cell_y + 1;
            celluleDestination = game->getMap()->getCellIfExists(x_dest, y_dest);
            if(celluleDestination != nullptr){
                game->getMap()->evaluerDeplacement(source, celluleDestination, pointsActuels);
            }

            //evaluer vers la gauche
            x_dest = selected_cell_x - 1;
            y_dest = selected_cell_y;
            celluleDestination = game->getMap()->getCellIfExists(x_dest, y_dest);
            if(celluleDestination != nullptr){
                game->getMap()->evaluerDeplacement(source, celluleDestination, pointsActuels);
            }

            //evaluer vers la droite
            x_dest = selected_cell_x - 1;
            y_dest = selected_cell_y;
            celluleDestination = game->getMap()->getCellIfExists(x_dest, y_dest);
            if(celluleDestination != nullptr){
                game->getMap()->evaluerDeplacement(source, celluleDestination, pointsActuels);
            }

            QColor activeColor = QColor(0, 0, 0, 128);
            QBrush brush(activeColor);
            QPainter painter(this);
            int squareSize = game->getTailleCellule();


            for (int x = 0; x < game->getColums(); x++) {
                for (int y = 0; y < game->getRows(); y++) {
                    Cellule* cell = this->game->getMap()->getCell(x, y);
                    if(cell->getPointsRestants() >= 0){
                        QRect rectangle(x * squareSize, y * squareSize, squareSize, squareSize);
                        QBrush brush(activeColor);
                        painter.fillRect(rectangle, brush);

                    }

                }

            }

        }
    }
}

void MainWindow::drawSelectableUnits(){
    QPainter painter(this);
    int squareSize = game->getTailleCellule();
    int opacity = 150;


    if(this->game != nullptr){
        Player* activePlayer = this->game->lp;

        QColor activeColor;
        if(activePlayer->getTeamColor() == "orange"){
            activeColor = QColor(255, 128, 0, opacity);
        } else {
            activeColor = QColor(0, 204, 0, opacity);
        }


        //iteration sur les cellules -> unités
        for (int x = 0; x < this->game->getColums(); x++) {
            for(int y = 0; y < this->game->getRows(); y++){
                Cellule* cell = this->game->getMap()->getCell(x, y);
                Unit* currentUnit = cell->getUnit();

                // si la cellule possède une unité
                if(currentUnit != nullptr){
                    // et que l'unité a le même owner que le joueur actif
                    if(currentUnit->getOwner() == activePlayer){
                        printf("trouvé une unité !!!! à afficher\n");

                        // definition rectangle
                        QRect rectangle(x * squareSize, y * squareSize, squareSize, squareSize);
                        QBrush brush(activeColor);
                        painter.fillRect(rectangle, brush);

                    }
                }
            }
        }
    }
}


void MainWindow::paintEvent(QPaintEvent *event) {
    drawCells();
    drawSelectableUnits();
    drawDestinationCells();
}



void :: MainWindow:: paintEventBuilding(std::string a, int x, int y){
    QPainter painter(this);
    painter.drawPixmap(game->getTailleCellule() *x,game->getTailleCellule() *y,game->getTailleCellule() ,game->getTailleCellule() ,dicoQPixMap[a]);
}


void MainWindow::mousePressEvent(QMouseEvent *event){
    qDebug()<< event->pos();
    this->game->play(event->x(), event->y());
    update();


}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
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
