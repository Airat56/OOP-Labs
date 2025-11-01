#ifndef CCIRCLE_H
#define CCIRCLE_H

#include <QPainter>
#include <QPoint>

class CCircle
{
public:
    CCircle(const QPoint &point);
    bool contains(const QPoint &point) const;
    void draw(QPainter &painter) const;
    void select(QPainter &painter) const;

private:
    static const int RADIUS = 30;
    QPoint _center;
};

#endif // CCIRCLE_H
