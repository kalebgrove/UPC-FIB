#include <iostream>

using namespace std;

int fatten(int x) {
    if(x < 10) return x;
    int fat = fatten(x/10);
    if(fat%10 < x%10) return fat*10 + x%10;
    return fat*10 + fat%10;
}

int main() {
    int n;
    while(cin >> n) cout << fatten(n) << endl;
}