#pragma once
#include <vector>
#include <QPointF>
#include <QGraphicsScene>

class PointsScene : public QGraphicsScene {
public:
    PointsScene();
    explicit PointsScene(QObject* parent = nullptr);
    void addPoints(const vector<QPointF>& qpoints);
};
