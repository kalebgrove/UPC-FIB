#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Rational {
    int num, den;
};

Rational simplify(int n, int d) {
    if (n == 0) {
        return Rational{0, 1};
    }

    int gcd = __gcd(n, d);
    n /= gcd;
    d /= gcd;

    if (d < 0) {
        n = -n;
        d = -d;
    }

    return Rational{n, d};
}

Rational operate(const Rational& r1, const Rational& r2, const string& op) {
    if (op == "add") {
        return simplify(r1.num * r2.den + r2.num * r1.den, r1.den * r2.den);
    } else if (op == "subtract") {
        return simplify(r1.num * r2.den - r2.num * r1.den, r1.den * r2.den);
    } else if (op == "multiply") {
        return simplify(r1.num * r2.num, r1.den * r2.den);
    } else {
        return simplify(r1.num * r2.den, r1.den * r2.num);
    }
}

int main() {
    Rational r;
    cin >> r.num >> r.den;
    r = simplify(r.num, r.den);
    cout << r.num << "/" << r.den << "\n";

    string op;
    while (cin >> op) {
        Rational r2;
        cin >> r2.num >> r2.den;
        r2 = simplify(r2.num, r2.den);
        r = operate(r, r2, op);
        if(r.den != 1) cout << r.num << "/" << r.den << "\n";
        else cout << r.num << "\n";
    }

}