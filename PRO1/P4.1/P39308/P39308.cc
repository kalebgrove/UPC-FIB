#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i*i < n; ++i) {
        if(n%i == 0) cout << n/i << endl;
    }
    for(int j = n; j*j > n; --j) {
        if(n%j == 0) cout << n/j << endl;
    }
}