#pragma once
#include <vector>
#include <QPointF>
#include <QGraphicsScene>
using namespace std;

class KDNode;
class PointsScene : public QGraphicsScene {
public:
    PointsScene();
    explicit PointsScene(QObject* parent = nullptr);
    void drawPoints(const vector<QPointF>& qpoints);
    void drawLines(const KDNode* node, const double xlow, const double xhigh,
                   const double ylow, const double yhigh, const bool axis);
};
