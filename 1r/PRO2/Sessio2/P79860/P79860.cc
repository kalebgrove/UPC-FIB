/* Bars(2)

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>

using namespace std;

void bars(int n) {
    //Base case:
    if(n == 0) return;
    for(int i = 0; i < n; ++i) cout << '*';
    cout << endl;
    for(int i = 0; i < 2; ++i) bars(n-1);
}

int main() {
    int n;
    cin >> n;

    bars(n);
}