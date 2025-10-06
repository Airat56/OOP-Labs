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

// наследование
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

    ColoredPoint(const ColoredPoint &p) {
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

// композиция с указателем
class Section {
public:
    Section() {
        printf("Section()\n");
        p1 = new Point;
        p2 = new Point;
    }

    Section(int x1, int y1, int x2, int y2) {
        printf("Section(int x1, int y1, int x2, int y2)\n");
        p1 = new Point(x1, y1);
        p2 = new Point(x2, y2);
    }

    Section(const Section &other) {
        printf("Section(const Section &other)\n");
        p1 = new Point(*other.p1);
        p2 = new Point(*other.p2);
    }

    ~Section() {
        delete p1;
        delete p2;
        printf("~Section()\n");
    }

public:
    Point *p1;
    Point *p2;
};

// композиция с объектом
class Circle {
public:
    Circle() {
        printf("Circle()\n");
        r = 0;
    }

    Circle(int x, int y, int r) : o(x, y) {
        printf("Circle(int x, int y)\n");
        this->r = r;
    }

    Circle(const Circle &other) : o(other.o) {
        printf("Circle(const Circle &other)\n");
        r = other.r;
    }

    ~Circle() {
        printf("~Circle()\n");
    }

public:
    Point o;
    int r;
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
        ColoredPoint *cp = new ColoredPoint(5, 10, 34);
        delete cp;
    }
    printf("----------------------------------------------------------------------\n");

    {
        // пример копирования объекта в объект того же самого класса
        Point p(4, 20);
        Point p2;
        p2 = p;
        p2.print();
        p2.move(10, 32);
        p.print();
    }
    printf("----------------------------------------------------------------------\n");

    {
        // примеры копирования указателя в указатель того же самого класса
        Point *p = new Point(4, 20);
        Point *p2;
        p2 = p;
        p2->print();
        p2->move(10, 32);
        p->print();
        delete p2;
    }
    printf("----------------------------------------------------------------------\n");

    {
        // пример помещения объектов в переменные различных типов
        Point *p = new ColoredPoint(5, 10, 34);
        ColoredPoint *p2 = new ColoredPoint(1, 5, 10);
        delete p;
        delete p2;
    }
    printf("----------------------------------------------------------------------\n");

    {
        // разница композиции с объектом и указателем
        Section s;
        Section s2(10, 20, 5, 18);
    }
    printf("----------------------------------------------------------------------\n");

    {
        // разница композиции с объектом и указателем
        Circle c;
        Circle c2(5, 20, 4);
    }
    printf("----------------------------------------------------------------------\n");

    return 0;
}
