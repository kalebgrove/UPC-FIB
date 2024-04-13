#include <iostream>

using namespace std;

int main() {
    int numspaces, numrows;
    while(cin >> numspaces >> numrows) {
        for(int i = 0; i < numspaces; ++i){
            cout << ' ';
        }
        cout << '*' << endl;

        for(int j = 0; j < numrows; ++j) {
            int space_outside_t = numspaces - 1;
            int space_inside = 1;
            for(int k = 0; k < numspaces; ++k) {                //From lines 18 to 29 we have the top middle part of the rhombus.
                for(int l = 0; l < space_outside_t; ++l) cout << ' ';
                cout << '*';
                for(int m = 0; m < 2*space_inside - 1; ++m) cout << ' ';
                cout << '*' << endl;
                ++space_inside;
                --space_outside_t;
            }
            int space_outside_b = 1;

            for(int o = 0; o < numspaces - 1; ++o) {                //From lines 30 to 39 we have the bottom middle part of the rhombus.
                for(int p = 0; p < space_outside_b; ++p) cout << ' ';
                cout << '*';
                for (int q = 2*space_inside - 5; q > 0; --q) cout << ' ';
                cout << '*' << endl;
                ++space_outside_b;
                --space_inside;              
            }
            for(int r = 0; r < numspaces; ++r) cout << ' ';
            cout << '*' << endl;
        }
        cout << endl;
    }
}