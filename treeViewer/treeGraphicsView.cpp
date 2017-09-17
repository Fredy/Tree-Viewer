#include "treeGraphicsView.hpp"
#include <QGraphicsView>
#include <QWheelEvent>
#include <cmath>

TreeGraphicsView::TreeGraphicsView() {}

TreeGraphicsView::TreeGraphicsView(QWidget *parent) : QGraphicsView(parent) {}

// From:
// http://www.qtcentre.org/threads/35738-How-to-zooming-like-in-AutoCAD-with-QGraphicsView
void TreeGraphicsView::wheelEvent(QWheelEvent *event) {
  if (event->modifiers().testFlag(
          Qt::ControlModifier)) { // zoom only when CTRL key pressed
    int numSteps = event->delta() / 15 / 8;

    if (numSteps == 0) {
      event->ignore();
      return;
    }
    const double sc = pow(1.25, numSteps); // I use scale factor 1.25
    this->zoom(sc, mapToScene(event->pos()));
    event->accept();
  } else {
    QGraphicsView::wheelEvent(event);
  }
}

void TreeGraphicsView::zoom(const double factor, const QPointF &centerPoint) {
  this->scale(factor, factor);
  this->centerOn(centerPoint);
}
