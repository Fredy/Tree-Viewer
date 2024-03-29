#-------------------------------------------------
#
# Project created by QtCreator 2017-09-08T00:27:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = treeViewer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++14

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainWindow.cpp \
    pointsScene.cpp \
    ../kdTree/kd_tree/kdTree.cpp \
    treeGraphicsView.cpp

HEADERS += \
        mainWindow.hpp \
    pointsScene.hpp \
    utils.hpp \
    ../kdTree/kd_tree/kdNode.hpp \
    ../kdTree/kd_tree/kdTree.hpp \
    ../kdTree/kd_tree/utils.hpp \
    treeGraphicsView.hpp

FORMS += \
        mainWindow.ui
