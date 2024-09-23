#include <iostream>

using namespace std;

int main() {
    int n;

while(cin >> n) {

    if(n != 0) cout << 1;

    int i = 2;

    while(n > 1) {
        bool hamming = true;
        int x = i;
        while(x > 1 and hamming) {
            if(x%2 == 0) x /= 2;
            else if(x%3 == 0) x /= 3;
            else if(x%5 == 0) x /= 5;
            else hamming = false;
        }
        if(hamming) {
            cout << ',' << i;
            --n;
        }
        ++i;
    }
    cout << endl;
}
}