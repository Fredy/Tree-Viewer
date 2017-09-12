#pragma once
#include <QGraphicsScene>
#include <QPointF>
#include <vector>
using namespace std;

class KDNode;
class PointsScene : public QGraphicsScene {
    Q_OBJECT
   private:
    vector<QColor> colors;
    vector<QGraphicsLineItem*> linesPtr;

    void drawLinesImp(const KDNode* node, const double xlow, const double xhigh,
                      const double ylow, const double yhigh, const bool axis,
                      const size_t color);

   public:
    PointsScene();

    explicit PointsScene(QObject* parent = nullptr);
    void drawPoints(const vector<QPointF>& qpoints);
    void drawLines(const KDNode* root);
   public slots:
    void showLines(int lineNumber);
};
