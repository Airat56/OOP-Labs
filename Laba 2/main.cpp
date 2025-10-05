#include <iostream>

class Point {
public:
    Point() {
        printf("Point()\n");
        x = 0;
        y = 0;
    }

    Point(int x, int y) {
        printf("Point(int x, int y)\n");
        this->x = x;
        this->y = y;
    }

    Point(const Point &p) {
        printf("Point(const Point &p)\n");
        x = p.x;
        y = p.y;
    }

    ~Point() {
        print();
        printf("~Point()\n");
    }

    // реализация метода сразу в определении
    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void move(int dx, int dy) {
        x = x + dx;
        y = y + dy;
    }

    void reset();

    void print() {
        printf("Point: x = %d, y = %d\n", x, y);
    }

protected:
    int x, y;
};

// реализация метода после определения
void Point::reset() {
    x = 0;
    y = 0;
}

class ColoredPoint: public Point {
public:
    ColoredPoint() : Point() {
        printf("ColoredPoint()\n");
        color = 0;
    }

    ColoredPoint(int x, int y, int color) : Point(x, y) {
        printf("ColoredPoint(int x, int y, int color)\n");
        this->color = color;
    }

    ColoredPoint(const ColoredPoint &p){
        printf("ColoredPoint(const ColoredPoint &p)\n");
        x = p.x;
        y = p.y;
        color = p.color;
    }

    ~ColoredPoint() {
        print();
        printf("~ColoredPoint()\n");
    }

    void change_color(int color) {
        this->color = color;
    }

    // переопределение метода в потомке
    void print() {
        printf("Point: x = %d, y = %d, color = %d\n", x, y, color);
    }

private:
    int color;
};

int main() {
    {
        // пример создания (с помощью различных конструкторов) и удаления статически создаваемых объектов
        Point p;
        Point p2(5, 10);
        Point p3(p2);
    }
    printf("----------------------------------------------------------------------\n");

    {
        // пример создания (с помощью различных конструкторов) и удаления динамически создаваемых объектов
        Point *p = new Point;
        Point *p2 = new Point(5, 10);
        Point *p3 = new Point(*p2);

        delete p;
        delete p2;
        delete p3;
    }
    printf("----------------------------------------------------------------------\n");

    {
        // пример использования методов объектов
        Point *p = new Point;
        p->set(5, 10);
        p->print();
        p->move(4, 7);
        p->print();
        p->reset();
        p->print();
        delete p;
    }
    printf("----------------------------------------------------------------------\n");

    {
        // пример создания и удаления объектов классов-наследников
        ColoredPoint *cp2 = new ColoredPoint(5, 10, 34);
        delete cp2;
    }
    printf("----------------------------------------------------------------------\n");

    return 0;
}
