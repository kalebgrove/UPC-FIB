#include <iostream>

using namespace std;

int main() {
    int n;
    
    while(cin >> n) {
        int n_blank = n - 1;
        int n_blank2 = 1;
        int star = n + 2;
        
        for(int i = 0; i < n - 1; ++i) {
            for(int n_space = 0; n_space < n_blank; ++n_space) {
                cout << ' ';
            }
            for(int j = 0; j < star - 2; ++j) {
                cout << 'X';
            }
            cout << endl;
            --n_blank;
            star += 2;
        }

        for (int k = 0; k < n; ++k) {
            for(int n_X = 0; n_X < star - 2; ++n_X) {
                cout << 'X';
            }
            cout << endl;
        }

        for(int l = 0; l < n - 1; ++l) {
            for(int n_space = 0; n_space < n_blank2; ++n_space) {
                cout << ' ';
            }
            for(int m = 0; m < star - 4; ++m) {
                cout << 'X';
            }
            cout << endl;
            star -= 2;
            ++n_blank2;
        }
    cout << endl;
    }
}