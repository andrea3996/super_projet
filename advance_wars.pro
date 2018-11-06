#-------------------------------------------------
#
# Project created by QtCreator 2018-10-22T13:53:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = advance-wars
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    player.cpp \
    map.cpp \
    cellule.cpp \
    unit.cpp \
    usine.cpp \
    ville.cpp \
    aeroport.cpp \
    infantery.cpp \
    bazooka.cpp \
    recon.cpp \
    tank.cpp \
    antiair.cpp \
    tankm.cpp \
    megatank.cpp \
    neotank.cpp \
    bcopter.cpp \
    fighter.cpp \
    bomber.cpp \
    game.cpp \
    Building/aeroport.cpp \
    Building/usine.cpp \
    Building/ville.cpp \
    Units/antiair.cpp \
    Units/bazooka.cpp \
    Units/bcopter.cpp \
    Units/bomber.cpp \
    Units/fighter.cpp \
    Units/infantery.cpp \
    Units/megatank.cpp \
    Units/neotank.cpp \
    Units/recon.cpp \
    Units/tank.cpp \
    Units/tankm.cpp \
    Units/unit.cpp \
    cellule.cpp \
    game.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    player.cpp \
    fmove.cpp

HEADERS += \
        mainwindow.h \
    game.h \
    player.h \
    map.h \
    cellule.h \
    unit.h \
    usine.h \
    ville.h \
    aeroport.h \
    infantery.h \
    bazooka.h \
    recon.h \
    tank.h \
    antiair.h \
    tankm.h \
    megatank.h \
    neotank.h \
    bcopter.h \
    fighter.h \
    bomber.h \
    Building/aeroport.h \
    Building/usine.h \
    Building/ville.h \
    Units/antiair.h \
    Units/bazooka.h \
    Units/bcopter.h \
    Units/bomber.h \
    Units/fighter.h \
    Units/infantery.h \
    Units/megatank.h \
    Units/neotank.h \
    Units/recon.h \
    Units/tank.h \
    Units/tankm.h \
    Units/unit.h \
    cellule.h \
    game.h \
    mainwindow.h \
    map.h \
    player.h \
    fmove.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    map1.txt \
    Resources/greenearthairport.gif \
    Resources/greenearthbase.gif \
    Resources/greenearthcity.gif \
    Resources/greenearthcomtower.gif \
    Resources/hbridge.gif \
    Resources/hpipe.gif \
    Resources/hriver.gif \
    Resources/hroad.gif \
    Resources/hshoal.gif \
    Resources/mountain.gif \
    Resources/plain.gif \
    Resources/reef.gif \
    Resources/sea.gif \
    Resources/wood.gif
