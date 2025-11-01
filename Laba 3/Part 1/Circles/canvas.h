#ifndef CANVAS_H
#define CANVAS_H

#include <container.h>
#include <container.cpp>
#include <ccircle.h>
#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QResizeEvent>

class Canvas : public QWidget {
public:
    Canvas(QWidget *parent = nullptr);
    ~Canvas();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    // void resizeEvent(QResizeEvent *event) override;

private:
    Container<CCircle*> _circles;
    Container<CCircle*> _selectedCircles;
};

#endif // CANVAS_H
