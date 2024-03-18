#include <iostream>

using namespace std;

void bin(int n) {
    if(n > 0) {
        bin(n/2);
        cout << n%2;
    }
}

void octa(int n) {
    if(n > 0) {
        octa(n/8);
        cout << n%8;
    }
}

void hexa(int n) {
    if(n > 0) {
        hexa(n/16);
        int num = n%16;
        if(num > 9) cout << char('A' + num - 10);
        else cout << num;
    }
}

int main() {
    int n;
    while(cin >> n) {
        if(n == 0) cout << "0 = 0, 0, 0" << endl;
        else {
            cout << n << " = ";
            bin(n);
            cout << ", ";
            octa(n);
            cout << ", ";
            hexa(n);
            cout << endl;
        }
        
    }
}