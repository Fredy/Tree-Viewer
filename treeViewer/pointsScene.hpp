#pragma once
#include <QGraphicsScene>
#include <QPointF>
#include <vector>
using namespace std;

class KDNode;
class PointsScene : public QGraphicsScene {
   public:
    PointsScene();

    vector<QColor> colors;
    explicit PointsScene(QObject* parent = nullptr);
    void drawPoints(const vector<QPointF>& qpoints);
    void drawLinesImp(const KDNode* node, const double xlow, const double xhigh,
                      const double ylow, const double yhigh, const bool axis,
                      const size_t color);
    void drawLines(const KDNode* root);
};
