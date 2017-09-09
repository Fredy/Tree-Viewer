#include "mainWindow.hpp"
#include "ui_mainWindow.h"
#include "pointsScene.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->graphicsView->setScene(new PointsScene(this));
}

MainWindow::~MainWindow() {
    delete ui;
}
