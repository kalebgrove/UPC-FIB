#include <iostream>

using namespace std;

int main() {
    int n;

    while(cin >> n) {
        int n_blank = n - 1;
        int n_x = n;
        for(int i = 0; i < n - 1; ++i) {
            for(int j = 0; j < n_blank; ++j) {
                cout << ' ';
            }
            for(int j = 0; j < n_x; ++j) {
                cout << 'X';
            }
            cout << endl;
            --n_blank;
            n_x += 2;
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n_x; ++j) {
                cout << 'X';
            }
            cout << endl;
        }
        for(int i = 0; i < n - 1; ++i) {
            for(int j = 0; j < n_blank + 1; ++j) {
                cout << ' ';
            }
            for(int j = 0; j < n_x - 2; ++j) {
                cout << 'X';
            }
            cout << endl;
            ++n_blank;
            n_x -= 2;
        }
        cout << endl;
    }
}