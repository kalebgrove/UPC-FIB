#include <iostream>

using namespace std;

int main() {
    int a, b;
    bool first = false;
    
    while(not first and cin >> a >> b) {
        int sum_a = 0, sum_b = 0;
        
        for(int i = 1; i < a; ++i) {
            if(a%i == 0) sum_a += i;
        }

        for(int i = 1; i < b; ++i) {
            if(b%i == 0) sum_b += i;
        }

        if(sum_a == b and sum_b == a and a != b) {
            cout << '(' << a << ' ' << b << ')';
            first = true;
        }
    }

    while (cin >> a >> b) {
        int sum_a = 0, sum_b = 0;

        for(int i = 1; i < a; ++i) {
            if(a%i == 0) sum_a += i;
        }

        for(int i = 1; i < b; ++i) {
            if(b%i == 0) sum_b += i;
        }

        if(sum_a == b and sum_b == a and a != b) cout << ",(" << a << ' ' << b << ')';
    }
    cout << endl;
}