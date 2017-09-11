#pragma once
#include <vector>
#include <string>
#include <QPointF>
using namespace std;

using Point = vector<string>;

inline QPointF latLongToQPoint(const double latitude, const double longitude) {
    // Latitude = y
    // Longitude = x
    // Inside is to center the points and zoom to expand them.
    const double zoom = 4.5;
    const double xinside = 190.0;
    const double yinside = 70.0;
    double y = zoom * (longitude + xinside);
    double x = zoom * (latitude + yinside) ;
    return QPointF(x, y);
}

inline vector<QPointF> generateQPoints(const vector<Point>& points) {
    // Convert a vector of Points into a vector of QPointF using
    // latLongToQPoint.
    vector<QPointF> qpoints(points.size());
    for (size_t i = 0; i < points.size(); i++) {
        qpoints[i] = latLongToQPoint(stod(points[i][0]),
                                     stod(points[i][1]));
    }
    return qpoints;
}
