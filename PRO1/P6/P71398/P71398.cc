#include <iostream>

using namespace std;

void digit_maxim_i_minim(int n, int& maxim, int& minim) {
    if(n == 0) return;

    if(n%10 > maxim) maxim = n%10;
    if(n%10 < minim) minim = n%10;
    return digit_maxim_i_minim(n/10, maxim, minim);
}

int main() {
    int n; 

    while(cin >> n) {
        int maxim = 0, minim = 10;
        if(n == 0) minim = 0;
        digit_maxim_i_minim(n, maxim, minim);
        cout << maxim << ' ' << minim << endl;
    }
}