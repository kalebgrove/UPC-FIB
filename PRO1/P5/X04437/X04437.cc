#include <iostream>
#include <math.h>

using namespace std;

double dist_or(double x, double y) {
    cout.setf(ios::fixed);
    cout.precision(4);
    return sqrt(x*x + y*y);
}

int main() {
    double distance = dist_or(634,371);
    cout << distance << endl;
}