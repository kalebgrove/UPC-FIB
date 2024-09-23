#include <iostream>

using namespace std;

int main() {
    int n;
    int count = 0;

    while(cin >> n and n != -1) {
        int b4 = 0;
        int x = n;
        while(x > 0) {             // We change the number to basis 4 and we add the numbers together, simultaneously.
            b4 += x%4;
            x /= 4;
        }
        int divider = 2*b4;

        if(n%divider == 0) ++count;
    }
    int x1 = count;
    int numbers = 0;
    while(x1 > 0) {
        x1 /= 10;
        ++numbers;
    }
    if(count == 0) cout << 0 << 0 << 0 << 0 << 0 << 0;
    else {
        for(int i = 0; i < 6 - numbers; ++i) {
            cout << 0;
        }
        cout << count;
    }
    cout << endl;
}