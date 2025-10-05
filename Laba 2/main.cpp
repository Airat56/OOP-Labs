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
        printf("Point(const Point &p)\n ");
        x = p.x;
        y = p.y;
    }

    ~Point() {
        printf("Point: x = %d, y = %d\n", x, y);
        printf("~Point()\n");
    }

private:
    int x, y;
};

int main() {
}
