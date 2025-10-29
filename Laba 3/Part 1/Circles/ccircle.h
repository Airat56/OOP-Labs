#ifndef CCIRCLE_H
#define CCIRCLE_H

class CCircle
{
public:
    CCircle(int x, int y);
    ~CCircle() = default;
    bool contains(const int &x, const int &y);
    void draw();
    void select();
    void unSelect();

private:
    static const int RADIUS = 30;
    int x;
    int y;
};

#endif // CCIRCLE_H
