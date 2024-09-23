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
    int d;
};

int dist(Point a, const int& x1, const int& y1) {
    return abs(a.c.x - x1) + abs(a.c.y - y1);
}

bool comp(Point a, Point b) {
    if(a.d != b.d) return a.d < b.d;
    if(a.c.x != b.c.x) return a.c.x < b.c.x;
    return a.c.y < b.c.y;
}

int main() {
    int x1, y1;
    cin >> x1 >> y1;

    int n;
    cin >> n;

    vector<Point> p(n);
    for(int i = 0; i < n; ++i) {
        cin >> p[i].c.x >> p[i].c.y;
        p[i].d = dist(p[i], x1, y1);
    }

    sort(p.begin(), p.end(), comp);

    int distance = -1;
    for(int i = 0; i < n; ++i) {
        if(p[i].d != distance) {
            cout << "points at distance " << p[i].d << endl;
            distance = p[i].d;
        }
        cout << p[i].c.x << ' ' << p[i].c.y << endl;
    }
}