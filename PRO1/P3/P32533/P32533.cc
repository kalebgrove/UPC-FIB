#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int plus = n - 1;
    int star = 0;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < plus; ++j) {
            cout << '+';
        }
        cout << '/';
        for(int k = 0; k < star; ++k) {
            cout << '*';
        }
        cout << endl;
        --plus;
        ++star;
    }
}