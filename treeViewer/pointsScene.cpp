#include "pointsScene.hpp"
#include "../kdTree/kd_tree/kdNode.hpp"
#include "utils.hpp"

PointsScene::PointsScene() {

}

PointsScene::PointsScene(QObject *parent) : QGraphicsScene(parent) {

}

void PointsScene::drawPoints(const vector<QPointF>& qpoints) {
    for (const auto& point: qpoints)
        // TODO: change ellipse with a custom class;
        this->addEllipse(point.x(), point.y(), 1, 1);
}

void PointsScene::drawLines(const KDNode* node, const double xlow,
                            const double xhigh, const double ylow,
                            const double yhigh, const bool axis) {
    // if axis == 1 : it is in X, if axis == 0 : it is in Y
    if (node == nullptr)
        return;
    // TODO: draw the line;
    QPointF point = latLongToQPoint(stod(node->data[0]),
                                    stod(node->data[1]));

    if (axis) {
        drawLines(node->childs[0], xlow, point.x(), ylow, yhigh, !axis);
        drawLines(node->childs[1], point.x(), xhigh, ylow, yhigh, !axis);
    }
    else {
        drawLines(node->childs[0], xlow, xhigh, ylow, point.y(), !axis);
        drawLines(node->childs[1], xlow, xhigh, point.y(), yhigh, !axis);
    }

}
