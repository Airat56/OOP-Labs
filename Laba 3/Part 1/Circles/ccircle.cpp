#include "ccircle.h"

CCircle::CCircle(const QPoint &point) : _center(point) {
}

bool CCircle::contains(const QPoint &point) const {
    int dx = point.x() - _center.x();
    int dy = point.y() - _center.y();
    return dx * dx + dy * dy <= RADIUS * RADIUS;
}

void CCircle::draw(QPainter &painter) const {
    painter.setBrush(Qt::red);
    painter.setPen(Qt::black);
    painter.drawEllipse(_center, RADIUS, RADIUS);
}

void CCircle::select(QPainter &painter) const {
    painter.setBrush(Qt::blue);
    painter.setPen(Qt::black);
    painter.drawEllipse(_center, RADIUS, RADIUS);
}
