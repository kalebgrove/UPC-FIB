#include <iostream>

using namespace std;

int main() {
    int r, c; // Rows and columns.
    cin >> r >> c;
    char coins;
    int sum = 0;

    while(cin >> coins) {
        
        sum += int(coins) - int('0');
        cin >> coins;
    }
    cout << sum << endl;
}