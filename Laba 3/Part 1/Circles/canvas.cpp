#include <canvas.h>

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    setFocusPolicy(Qt::StrongFocus);
}

Canvas::~Canvas() {
    for (int i = 0; i < _selectedCircles.getSize(); i++) {
        _selectedCircles.setObject(i, nullptr);
    }

    for (int i = 0; i < _circles.getSize(); i++) {
        delete _circles.getObject(i);
        _circles.setObject(i, nullptr);
    }
}

void Canvas::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
}

void Canvas::mousePressEvent(QMouseEvent *event) {
    if (event->button() != Qt::LeftButton) {
        QWidget::mousePressEvent(event);
        return;
    }

    QPoint pos = event->pos();
    bool isCtrlPressed = event->modifiers() & Qt::ControlModifier;

    if (false) {
        // если нажал на круг
    } else {
        // если нажал на пустое место
        if (!isCtrlPressed) {
            if (_selectedCircles.getSize() == 0) {
                // если круги не выделены, создаём круг
                _circles.pushBack(new CCircle(pos));
            } else {
                // если кругы выделены, снимаем выделение
                _selectedCircles.clear();
            }
        }
    }

    update();
}

void Canvas::keyPressEvent(QKeyEvent *event) {
    //
}
