#include <iostream>
#include <math.h>

using namespace std;

int square(int n) {
    return n*n;
}

double root(int n) {
    cout.setf(ios::fixed);
    cout.precision(6);
    return sqrt(n);
}

int main() {

    int n;
    while(cin >> n) {
        int sq = square(n);
        double qroot = root(n);

        cout << sq << ' ' << qroot << endl;
    }
}