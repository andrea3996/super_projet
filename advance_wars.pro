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
    game.cpp \
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
    bomber.cpp

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
    bomber.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    map1.txt
