#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Fraction {
    int num, den;
};

void simplify(int num, int den) {
    if (num == 0) {
        den = 1;
    }

    int gcd = __gcd(num, den);
    num /= gcd;
    den /= gcd;

    // Ensure the denominator is positive
    if (den < 0) {
        num = -num;
        den = -den;
    }

    //Print the outcome:
    cout << num << '/' << den << endl;
}

Fraction addition(const Fraction& x, const Fraction& y) {
    Fraction res;
    int lcm = (x.den*y.den)/(__gcd(x.den, y.den));

    res.num = (lcm/x.den)+(lcm/y.den);

    res.den = lcm;

    simplify(res.num, res.den);
}

int main() {
    Fraction x;
    char c;
    
    cin >> x.num >> c >> x.den;

    char sum;
    while(cin >> sum and sum != '=') {
        Fraction y;
        cin >> y.num >> c >> y.den;

        
    }
}