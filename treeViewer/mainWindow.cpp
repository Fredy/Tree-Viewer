#include "mainWindow.hpp"
#include "../kdTree/kd_tree/kdTree.hpp"
#include "../kdTree/kd_tree/utils.hpp"
#include "pointsScene.hpp"
#include "ui_mainWindow.h"
#include "utils.hpp"
#include <QDebug>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  pscene = new PointsScene(this);
  // pscene->setSceneRect(QRectF(0, 0, 1000, 1000));
  ui->graphicsView->setScene(pscene);

  ifstream file("crime50k_just_coords.csv");
  // ifstream file("test1.csv");

  auto points = readCSV(file, true);
  auto qpoints = generateQPoints(points);

  pscene->drawPoints(qpoints);
  KDTree tree(points, 1000);
  QRectF tmpRect = pscene->sceneRect();
  const double gap = 5.0;
  pscene->drawLines(tree.root, tmpRect.left() - gap, tmpRect.right() + gap,
                    tmpRect.top() - gap, tmpRect.bottom() + gap);
  pscene->drawBoundingRect(tmpRect.left() - gap, tmpRect.top() - gap,
                           tmpRect.width() + gap * 2,
                           tmpRect.height() + gap * 2);

  connect(ui->spinBox, SIGNAL(valueChanged(int)), pscene, SLOT(showLines(int)));
}

MainWindow::~MainWindow() {
  delete ui;
  delete pscene;
}
