#include <fstream>
#include "mainWindow.hpp"
#include "ui_mainWindow.h"
#include "pointsScene.hpp"
#include "utils.hpp"
#include "../kdTree/kd_tree/utils.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    pscene = new PointsScene(this);
    pscene->setSceneRect(QRectF(0, 0, 700, 700));
    ui->graphicsView->setScene(pscene);
    ifstream file("just_coordinates.csv");
    auto points = readCSV(file, true);
    auto qpoints = generateQPoints(points);
    pscene->drawPoints(qpoints);
}

MainWindow::~MainWindow() {
    delete ui;
    delete pscene;
}
