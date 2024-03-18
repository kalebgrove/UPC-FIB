#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Coordinates {
    int x, y;
};

struct Point {
    Coordinates c;
    int distance;
};

int dist(Point a, const int& x1, const int& y1) {
    return abs(a.c.x - x1) + abs(a.c.y - y1);
}

bool comp(Point a, Point b) {
    return a.distance < b.distance;
}

int main() {
    int x1, y1;
    cin >> x1 >> y1;

    int n;
    cin >> n;

    vector<Point> p(n);
    for(int i = 0; i < n; ++i) {
        cin >> p[i].c.x >> p[i].c.y;
        p[i].distance = dist(p[i], x1, y1);
    }

    sort(p.begin(), p.end(), comp);

    for(int i = 0; i < n; ++i) {
        cout << p[i].c.x << ' ' << p[i].c.y << endl;
    }
}