#pragma once
#include <QPointF>
#include <string>
#include <vector>
using namespace std;

using Point = vector<string>;

inline QPointF xyScale(const double _x, const double _y,
                               const double scale = 10000.0) {
  // Latitude = y
  // Longitude = x
  // Inside is to center the points and zoom to expand them.
  const double x = scale * _x;
  const double y = scale * _y;
  return QPointF(x, y);
}

inline vector<QPointF> generateQPoints(const vector<Point> &points) {
  // Convert a vector of Points into a vector of QPointF using
  // latLongToQPoint.
  vector<QPointF> qpoints(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    qpoints[i] = xyScale(stod(points[i][0]), stod(points[i][1]));
  }
  return qpoints;
}
