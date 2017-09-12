#include "mainWindow.hpp"
#include <fstream>
#include "../kdTree/kd_tree/kdTree.hpp"
#include "../kdTree/kd_tree/utils.hpp"
#include "pointsScene.hpp"
#include "ui_mainWindow.h"
#include "utils.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    pscene = new PointsScene(this);
    pscene->setSceneRect(QRectF(0, 0, 1000, 4000));
    ui->graphicsView->setScene(pscene);

    ifstream file("just_coordinates.csv");
    // ifstream file("test1.csv");
    auto points = readCSV(file, true);
    auto qpoints = generateQPoints(points);
    pscene->drawPoints(qpoints);

    KDTree tree(points, 1000);
    pscene->drawLines(tree.root);

    connect(ui->spinBox, SIGNAL(valueChanged(int)), pscene, SLOT(showLines(int)));
}

MainWindow::~MainWindow() {
    delete ui;
    delete pscene;
}
