#include <iostream>

using namespace std;

int main() {
    int n, rows;
    cin >> n >> rows;
    int x = n;
    int count = 0;

    while(x > 0) {
        x /= 10;
        ++count;
    }
    if(n == 0) count = 1;

    int dots = count * rows*2 + (2*rows - 2) - count*2 + 1;   // Here we find the amount of dots we print, that will progressively reduce until one dot is left.
    int num = 1;
    int sub = count*2 + 2;

    for(int i = 0; i < rows; ++i) {
        cout << n;
        for(int j = 0; j < num - 1; ++j) {
            if(num > 1) cout << '-';
            cout << n;
        }
        for(int j = 0; j < dots; ++j) {
            cout << '.';
        }
        cout << n;
        for(int j = 0; j < num - 1; ++j) {
            if(num > 1) cout << '-';
            cout << n;
        }
        cout << endl;
        ++num;
        dots = dots - sub;
    }
}