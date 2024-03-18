#include <iostream>

using namespace std;

int main() {
    int b; // Base
    cin >> b;

    int n; // Number represented according to line 6.
    int n_b = 0; // Number that will be represented in the output.

    while(cin >> n) {
        int aux = n;
        while(n > 0) {
            n_b = (n%b) + n_b;
            n /= b;
        }
        cout << aux << ": " << n_b << endl;
        n_b = 0;
    }
}