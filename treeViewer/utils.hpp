#pragma once
#include <vector>
#include <string>
#include <QPointF>
using namespace std;

using Point = vector<string>;

inline vector<QPointF> generateQPoints(const vector<Point>& points) {
    vector<QPointF> qpoints(points.size());
    for (size_t i = 0; i < points.size(); i++) {
        double x = stod(points[i][0]);
        double y = stod(points[i][1]);
        qpoints[i] = QPointF(x,y);
    }

    return qpoints;
}
