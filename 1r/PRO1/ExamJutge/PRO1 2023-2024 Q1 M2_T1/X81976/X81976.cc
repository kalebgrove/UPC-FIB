#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int main() {
    int n, m;
    char x;

    while(cin >> n >> m) {

        VVI matrix(n, VI(m)); //Matrix;
        VVI rows(n, VI(10, 0)); //Freqüency matrix;
        VVI columns(m, VI(10, 0)); // Freqüency matrix;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> x;
                matrix[i][j] = x - '0';
                ++rows[i][matrix[i][j]];
                ++columns[j][matrix[i][j]];
            }
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cout << ((rows[i][matrix[i][j]])%10 + (columns[j][matrix[i][j]])%10)%10;
            }
            cout << endl;
        }
        cout << endl;
    }
}