#include <iostream>

using namespace std;

int sum_divisors(int a) {
    int sum = 0;
    for(int i = 1; i < a; ++i) {
        if(a%i == 0) sum += i;
    }
    return sum;
}

int main() {
    int a, b;
    bool first = false;
    
    while(not first and cin >> a >> b) {
        if(sum_divisors(a) == b and sum_divisors(b) == a and a != b) {
            cout << '(' << a << ' ' << b << ')';
            first = true;
        }
    }

    while (cin >> a >> b) {
        if(sum_divisors(a) == b and sum_divisors(b) == a and a != b) cout << ",(" << a << ' ' << b << ')';
    }
    cout << endl;
}