#include "pointsScene.hpp"
#include "../kdTree/kd_tree/kdNode.hpp"
#include "utils.hpp"

PointsScene::PointsScene() {}

PointsScene::PointsScene(QObject* parent) : QGraphicsScene(parent) {
    this->colors = {{"#2a3996"}, {"#f9294a"}, {"#36aafd"},
                    {"#609f1c"}, {"#bd7f3e"}, {"#ff4500"}};
}

void PointsScene::drawPoints(const vector<QPointF>& qpoints) {
    for (const auto& point : qpoints)
        // TODO: change ellipse with a custom class;
        this->addEllipse(point.x(), point.y(), 1, 1);
}

void PointsScene::drawLinesImp(const KDNode* node, const double xlow,
                               const double xhigh, const double ylow,
                               const double yhigh, const bool axis,
                               const size_t color) {
    // if axis == 1 : it is in X, if axis == 0 : it is in Y
    if (node == nullptr) return;
    // TODO: draw the line;
    QPointF point = latLongToQPoint(stod(node->data[0]), stod(node->data[1]));

    if (axis) {
        this->addLine(point.x(), ylow, point.x(), yhigh, this->colors[color]);
        drawLinesImp(node->childs[0], xlow, point.x(), ylow, yhigh, !axis,
                     (color + 1) % this->colors.size());
        drawLinesImp(node->childs[1], point.x(), xhigh, ylow, yhigh, !axis,
                     (color + 1) % this->colors.size());
    } else {
        this->addLine(xlow, point.y(), xhigh, point.y(), this->colors[color]);
        drawLinesImp(node->childs[0], xlow, xhigh, ylow, point.y(), !axis,
                     (color + 1) % this->colors.size());

        drawLinesImp(node->childs[1], xlow, xhigh, point.y(), yhigh, !axis,
                     (color + 1) % this->colors.size());
    }
}

void PointsScene::drawLines(const KDNode* root) {
    if (root == nullptr) return;
    QPointF point = latLongToQPoint(stod(root->data[0]), stod(root->data[1]));
    this->addLine(point.x(), 0, point.x(), 5000, this->colors[0]);
    drawLinesImp(root->childs[0], 0, point.x(), 0, 5000, 0, 1);
    drawLinesImp(root->childs[1], point.x(), 5000, 0, 5000, 0, 1);
}
