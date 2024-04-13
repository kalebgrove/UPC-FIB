#include <iostream>

using namespace std;

//pre: a and b are non-negative. Moreover a > 0 or b > 0 
//post: computes the funny coefficient couple x and y defined above.
//      It holds xa + yb = gcd(a,b)
void funny_coeffs(int a, int b, int& x, int& y) {
    if(b == 0) {
        x = 1;
        y = 0;
    } else {
        int x_temp, y_temp;
        funny_coeffs(b, a%b, x_temp, y_temp);
        x = y_temp;
        y = x_temp - (a/b)*y_temp;
    }
}

int main() {
    int a, b;
    while(cin >> a >> b) {
        int x, y;
        if(a <= b) funny_coeffs(a, b, x, y);
        else funny_coeffs(b, a, y, x);

        cout << x << ' ' << y << ' ' << x*a+y*b << endl;
    }
}