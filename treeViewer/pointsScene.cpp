#include "pointsScene.hpp"
#include "../kdTree/kd_tree/kdNode.hpp"
#include "utils.hpp"
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>

PointsScene::PointsScene() { this->crrntPointPtr = nullptr; }

PointsScene::PointsScene(QObject *parent) : QGraphicsScene(parent) {
  this->colors = {{"#2a3996"}, {"#f9294a"}, {"#36aafd"},
                  {"#609f1c"}, {"#bd7f3e"}, {"#ff4500"}};
  this->crrntPointPtr = nullptr;
}

void PointsScene::drawPoints(const vector<QPointF> &qpoints) {
  for (const auto &point : qpoints) {
    // TODO: change ellipse with a custom class;
    QGraphicsEllipseItem *tmpPtr =
        this->addEllipse(point.x() - 1, point.y() - 1, 2, 2);
    // TODO: make one more drawPoint function that draw the 'normal'
    // points, the botom one draws 'guide' points.
    tmpPtr->setZValue(1);
  }
}
QGraphicsEllipseItem *PointsScene::drawPoint(const double x, const double y,
                                             const double radius) {
  QGraphicsEllipseItem *tmpPtr =
      this->addEllipse(x - radius / 2, y - radius / 2, radius, radius);
  tmpPtr->setZValue(1230);
  tmpPtr->setVisible(false);
  tmpPtr->setBrush(QBrush(Qt::red));
  return tmpPtr;
}

// TODO: add a way to visualize the actual point, and its data.
// and fix the scale.
// TODO: use the tree depht to limit this !!!!
void PointsScene::drawLinesImp(const KDNode *node, const double xlow,
                               const double xhigh, const double ylow,
                               const double yhigh, const bool axis,
                               const size_t color) {
  // if axis == 1 : it is in X, if axis == 0 : it is in Y
  if (node == nullptr)
    return;

  QPointF point = xyScale(stod(node->data[0]), stod(node->data[1]));

  QGraphicsEllipseItem *pointPtr = this->drawPoint(point.x(), point.y(), 4);
  this->pointsPtr.push_back(pointPtr);

  if (axis) {
    QGraphicsLineItem *lineptr =
        this->addLine(point.x(), ylow, point.x(), yhigh, this->colors[color]);
    lineptr->setZValue(-110);
    this->linesPtr.push_back(lineptr);

    drawLinesImp(node->childs[0], xlow, point.x(), ylow, yhigh, !axis,
                 (color + 1) % this->colors.size());
    drawLinesImp(node->childs[1], point.x(), xhigh, ylow, yhigh, !axis,
                 (color + 1) % this->colors.size());
  } else {
    QGraphicsLineItem *lineptr =
        this->addLine(xlow, point.y(), xhigh, point.y(), this->colors[color]);
    this->linesPtr.push_back(lineptr);

    drawLinesImp(node->childs[0], xlow, xhigh, ylow, point.y(), !axis,
                 (color + 1) % this->colors.size());

    drawLinesImp(node->childs[1], xlow, xhigh, point.y(), yhigh, !axis,
                 (color + 1) % this->colors.size());
  }
}

void PointsScene::drawLines(const KDNode *root, const double xlow,
                            const double xhigh, const double ylow,
                            const double yhigh) {
  if (root == nullptr)
    return;
  QPointF point = xyScale(stod(root->data[0]), stod(root->data[1]));
  QGraphicsLineItem *lineptr =
      this->addLine(point.x(), ylow, point.x(), yhigh, this->colors[0]);

  QGraphicsEllipseItem *pointPtr = this->drawPoint(point.x(), point.y(), 4);
  this->pointsPtr.push_back(pointPtr);

  this->linesPtr.push_back(lineptr);

  drawLinesImp(root->childs[0], xlow, point.x(), ylow, yhigh, 0, 1);
  drawLinesImp(root->childs[1], point.x(), xhigh, ylow, yhigh, 0, 1);

  this->crrntPointPtr = pointPtr;
}

void PointsScene::drawBoundingRect(double x, double y, double width,
                                   double height) {
  this->addRect(x, y, width, height);
}

void PointsScene::showLines(int lineNumber) {
  const int size = this->linesPtr.size();
  if (lineNumber >= size) {
    for (int i = 0; i < size; i++)
      this->linesPtr[i]->setVisible(true);

  } else {
    for (int i = 0; i < lineNumber; i++)
      this->linesPtr[i]->setVisible(true);
    for (int i = lineNumber; i < size; i++)
      this->linesPtr[i]->setVisible(false);
    if (lineNumber > 0) {
      this->crrntPointPtr->setVisible(false);
      this->pointsPtr[lineNumber - 1]->setVisible(true);
      this->crrntPointPtr = this->pointsPtr[lineNumber - 1];
    } else {
      this->crrntPointPtr->setVisible(false);
    }
  }
}
