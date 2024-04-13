#include <iostream>

using namespace std;

int main() {
    int n;

    while(cin >> n) {
        int x = n;
        int dig = 1;
        while(x > 9) {
            x /= 10;
            ++dig;
        }
        int sum = 0;
        while(dig > 0) {
            sum += dig*(n%10);
            --dig;
            n /= 10;
        }
        cout << sum << endl;
    }
}