#include <canvas.h>

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    setFocusPolicy(Qt::StrongFocus);
}

Canvas::~Canvas() {
    _selectedCircles.clear();

    for (int i = 0; i < _circles.getSize(); i++) {
        delete _circles.getObject(i);
    }
}

void Canvas::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    for (int i = 0; i < _circles.getSize(); i++) {
        _circles.getObject(i)->draw(painter);
    }

    for (int i = 0; i < _selectedCircles.getSize(); i++) {
        _selectedCircles.getObject(i)->select(painter);
    }

    QWidget::paintEvent(event);
}

void Canvas::mousePressEvent(QMouseEvent *event) {
    if (event->button() != Qt::LeftButton) {
        QWidget::mousePressEvent(event);
        return;
    }

    QPoint pos = event->pos();
    bool isCtrlPressed = event->modifiers() & Qt::ControlModifier;
    Container<CCircle*> hitCircles;

    // сохраняем все круги, в которые попали
    for (int i = 0; i < _circles.getSize(); i++) {
        CCircle *circle = _circles.getObject(i);
        if (circle->contains(pos)) {
            hitCircles.pushBack(circle);
        }
    }

    if (hitCircles.getSize() != 0) {
        // если нажал на круг
        if (isCtrlPressed) {
            for (int i = 0; i < hitCircles.getSize(); i++) {
                bool isSelected = false;
                CCircle *currentHitCircle = hitCircles.getObject(i);
                for (int j = 0; j < _selectedCircles.getSize(); j++) {
                    if (currentHitCircle == _selectedCircles.getObject(j)) {
                        // если круг уже выделен, снять выделение
                        _selectedCircles.erase(j);
                        isSelected = true;
                        break;
                    }
                }

                if (!isSelected) {
                    // если нет, выделить
                    _selectedCircles.pushBack(currentHitCircle);
                }
            }
        } else {
            _selectedCircles.clear();
            for (int i = 0; i < hitCircles.getSize(); i++) {
                _selectedCircles.pushBack(hitCircles.getObject(i));
            }
        }
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
    QWidget::mousePressEvent(event);
}

void Canvas::keyPressEvent(QKeyEvent *event) {
    //
}
