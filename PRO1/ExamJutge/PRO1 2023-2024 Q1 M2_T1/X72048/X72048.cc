#include <iostream>
#include <string>

using namespace std;

void recursive(int n) {
    if(n == 0) cout << 0;
    for(int i = n; i > 0; --i) {
        if(i == n) cout << n;
        recursive(n-1);
        cout << n;
    }
}

int main() {
    int n;

    while(cin >> n) {
        recursive(n);
        cout << endl;
    }
}