#pragma once
#include <QGraphicsView>

class TreeGraphicsView : public QGraphicsView {
  Q_OBJECT
private:
  bool isTouched;
  QPointF mousePos;

public:
  TreeGraphicsView();
  TreeGraphicsView(QWidget *parent = nullptr);
  void zoom(const double factor, const QPointF &centerPoint);

protected:
  void wheelEvent(QWheelEvent *event);
};
