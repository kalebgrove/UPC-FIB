#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rational {
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

    if(den != 1) cout << num << '/' << den << endl;
    else cout << num << endl;
}

void add(Rational& r, Rational r2) {
    if(r.den != r2.den) {
        int lcm = (r.den*r2.den)/(__gcd(r.den, r2.den));

        r.num *= (lcm/r.den);
        r2.num *= (lcm/r2.den);

        r.den = lcm;
    }

    r.num += r2.num;

    simplify(r.num, r.den);
}

void substract(Rational& r, Rational r2) {
    if(r.den != r2.den) {
        int lcm = (r.den*r2.den)/(__gcd(r.den, r2.den));

        r.num *= (lcm/r.den);
        r2.num *= (lcm/r2.den);

        r.den = lcm;
    }

    r.num -= r2.num;

    simplify(r.num, r.den);
}

void multiply(Rational& r, Rational r2) {
    r.num *= r2.num;
    r.den *= r2.den;

    simplify(r.num, r.den);
}

void divide(Rational& r, Rational r2) {
    r.num *= r2.den;
    r.den *= r2.num;

    simplify(r.num, r.den);
}

int main() {
    Rational r;
    cin >> r.num >> r.den;

    simplify(r.num, r.den);

    string op;

    while(cin >> op) {
        Rational r2;
        cin >> r2.num >> r2.den;

        if(op == "add") add(r, r2);
        else if(op == "substract") substract(r, r2);
        else if(op == "multiply") multiply(r, r2);
        else divide(r, r2);
    }
}