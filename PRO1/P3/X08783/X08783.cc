#include <iostream>

using namespace std;

int main() {
    int n, b;
    int sum = 1;

    while(cin >> b >> n) {
        while(n >= b) {
            n /= b;
            ++sum;
        }
        cout << sum << endl;
        sum = 1;
    }
}