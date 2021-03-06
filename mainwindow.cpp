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

    setFixedSize(game->getTailleCellule()*game->getColums()+100, game->getTailleCellule()*game->getRows());
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
                if (this->game->getMap()->getCell(j, i)->getUnit()->getOwner()->getTeamColor() == "green"){
                painter.drawPixmap(game->getTailleCellule() *j,game->getTailleCellule() *i,game->getTailleCellule() ,game->getTailleCellule() ,dicoQPixUnit[unitType]);
                }
                else {
                painter.drawPixmap(game->getTailleCellule() *j,game->getTailleCellule() *i,game->getTailleCellule() ,game->getTailleCellule() ,dicoQPixUnit[unitType+"R"]);
                }
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

void MainWindow::drawSelectableUnits(){
    QPainter painter(this);
    int squareSize = game->getTailleCellule();
    int opacity = 150; // opacité du voile


    if(this->game != nullptr){
        Player* activePlayer = this->game->lp;

        QColor activeColor;
        if(activePlayer->getTeamColor() == "orange"){
            activeColor = QColor(255, 128, 0, opacity); // vecteur couleur
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

void MainWindow::drawDestinationCells(){
    QPainter painter(this);
    QColor activeColor = QColor(0, 0, 0, 128);
    QBrush brush(activeColor);
    int tc = game->getTailleCellule();
    if ( game->getUnitSelected() != nullptr){
        qDebug() << game->getUnitSelected()->getListCasesDispo().size();

        std :: string identity = game->getUnitSelected()->getIdentity();
        if (game->getUnitSelected()->getOwner()->getTeamColor() != "green"){
            identity = identity + "R";
        }
        painter.drawPixmap(game->getTailleCellule()*game->getColums(),0,game->getTailleCellule()*2 ,game->getTailleCellule()*2 ,dicoQPixUnit[identity]);
        QString pointDeVie = "Points de vie: " + QString::number(game->getUnitSelected()->getPointsDeVie());
        QPoint p(game->getTailleCellule()*game->getColums(),game->getTailleCellule()*2+5);
        painter.drawText(p,pointDeVie);
        for ( size_t cd = 0; cd < game->getUnitSelected()->getListCasesDispo().size(); cd++ ) {
            int xa = game->getUnitSelected()->getListCasesDispo()[cd]->getCelluleDispo().first;
            int ya = game->getUnitSelected()->getListCasesDispo()[cd]->getCelluleDispo().second;
            QRect rectangle( xa * tc, ya * tc, tc, tc);
            QBrush brush(activeColor);
            painter.fillRect(rectangle, brush);

            int xb = game->getUnitSelected()->getListCasesDispo()[cd]->getCellulePrecedente().first;
            int yb = game->getUnitSelected()->getListCasesDispo()[cd]->getCellulePrecedente().second;
            int dx = xb - xa;
            int dy = yb - ya;
            // dx = dy = 0;
            //std::cout << "(" << dx << " " << dy << std::endl;
            painter.fillRect(xa * tc + dx * tc/4 + tc/4, ya * tc + dy * tc/4 + tc/4, tc/2, tc/2, Qt::red);
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
    dicoQPixUnit.insert({"AntiAirR", QPixmap(":/unit/antiairR.png")});
    dicoQPixUnit.insert({"BcopterR", QPixmap(":/unit/bcopterR.png")});
    dicoQPixUnit.insert({"BomberR", QPixmap(":/unit/bomberR.png")});
    dicoQPixUnit.insert({"FighterR", QPixmap(":/unit/fighterR.png")});
    dicoQPixUnit.insert({"InfantryR", QPixmap(":/unit/osinfantry.png")});
    dicoQPixUnit.insert({"MegaTankR", QPixmap(":/unit/megatankR.png")});
    dicoQPixUnit.insert({"NeoTankR", QPixmap(":/unit/neotankR.png")});
    dicoQPixUnit.insert({"ReconR", QPixmap(":/unit/reconR.png")});
    dicoQPixUnit.insert({"TankMR", QPixmap(":/unit/tankR.png")});


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

void MainWindow::openAttaqueWindow() {
    AttaqueWindow attaqueWindow(nullptr, game);
    attaqueWindow.setModal(true);
    attaqueWindow.exec();
}
