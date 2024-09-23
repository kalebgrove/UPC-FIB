#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rational {
    int num, den;
};

Rational rational(int n, int d) {
    // Precondition: d ≠ 0
    if (n == 0) {
        return Rational{0, 1};
    }

    int gcd = __gcd(n, d);
    n /= gcd;
    d /= gcd;

    // Ensure the denominator is positive
    if (d < 0) {
        n = -n;
        d = -d;
    }

    return Rational{n, d};
}