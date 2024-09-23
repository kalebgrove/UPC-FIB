#include <iostream>

using namespace std;

void rhombus(int n, int s) {
    if(n == 1) {
        for(int i = 0; i < s-n; ++i) cout << ' ';
        cout << '*' << endl;
    } else {
        rhombus(n-1, s);

        for(int i = 0; i < n-1; ++i) {
            for(int j = 0; j < s-i-2; ++j) cout << ' ';
            for(int j = 0; j < 2*i+3; ++j) cout << '*';
            cout << endl;
        }

        for(int i = 0; i < n-2; ++i) {
            for(int j = 0; j < s-n+i+1; ++j) cout << ' ';
            for(int j = 0; j < 2*n-3-2*i; ++j) cout << '*';
            cout << endl;
        }
        rhombus(n-1, s);
    }
}

int main() {
    int n;
    while(cin >> n) {
        rhombus(n, n);
        cout << endl;
    }
}