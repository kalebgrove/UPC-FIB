#include <iostream>
#include <math.h>

using namespace std;

double sine(double n) {
    cout.setf(ios::fixed);
    cout.precision(6);
    return sin(n);
}

double cosine(double n) {
    cout.setf(ios::fixed);
    cout.precision(6);
    return cos(n);
}

int main() {
    double n;
    while(cin >> n) {
        double sin = sine(n*M_PI/180);
        double cos = cosine(n*M_PI/180);

        cout << sin << ' ' << cos << endl;
    }
}