#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;
};

struct Circle{
    Point center;
    double radius;
};

void move(Point& p1, const Point& p2) {
    p1.x += p2.x;
    p1.y += p2.y;
}

void scale(Circle& c, double sca) {
    c.radius *= sca;
}

void move(Circle& c, const Point& p) {
    
}