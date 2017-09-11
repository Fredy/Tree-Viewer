#include <fstream>
#include "mainWindow.hpp"
#include "ui_mainWindow.h"
#include "pointsScene.hpp"
#include "utils.hpp"
#include "../kdTree/kd_tree/utils.hpp"
#include "../kdTree/kd_tree/kdTree.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    pscene = new PointsScene(this);
    pscene->setSceneRect(QRectF(0, 0, 1000, 4000));
    ui->graphicsView->setScene(pscene);
    // ("just_coordinates.csv")
    ifstream file("just_coordinates.csv");
    //ifstream file("test1.csv");
    auto points = readCSV(file, true);
    auto qpoints = generateQPoints(points);
    pscene->drawPoints(qpoints);

    KDTree tree(points,1000);
    pscene->drawLines(tree.root);
}

MainWindow::~MainWindow() {
    delete ui;
    delete pscene;
}
