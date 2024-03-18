#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int others;
    int num;
    int cnt = 0;
    
    cout << "nombres que acaben igual que " << n << ':' << endl;
    while(cin >> others) {
        num = n%1000;
        if((others-num)%1000 == 0) {
            ++cnt;
            cout << others << endl;
        }
    }
    cout << "total: " << cnt << endl;
}