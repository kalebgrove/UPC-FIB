/* Recursivitat alterna

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>
#include <cmath>

using namespace std;

void recursive(int n, int m) {
    if(n == 0) {
        for(int i = 0; i < m; ++i) cout << ' ';
        cout << '*' << endl;
    } else {
        if(n%2 == 0) {
            recursive(n-1, m);
            recursive(n-1, m+pow(2, n-1));
        } else {
            recursive(n-1, m+pow(2, n-1));
            recursive(n-1, m);
        }
    }
}

int main() {
    int n;
    while(cin >> n) {
        recursive(n, 0);
        cout << "----------\n";
    }
}