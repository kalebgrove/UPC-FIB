#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > VVI;
typedef vector<int> VI;

bool squares(const VVI& matrix) {
    int a = 0, b = 0;
    for(int i = 0; i < 9; ++i) {
        VI freq_s(9, 0);
        for(int k = a; k < a+3; ++k) {
            for(int l = b; l < b+3; ++l) {
                ++freq_s[matrix[k][l]-1];
                if(freq_s[matrix[k][l]-1] > 1) return false;
            }
        }
        b += 3;
        if(b > 6) {
                b = 0;
                a += 3;
        }

        VI freq_rows(9, 0);
        VI freq_col(9, 0);
        for(int j = 0; j < 9; ++j) {
            ++freq_rows[matrix[i][j]-1];
            ++freq_col[matrix[j][i]-1];
            if(freq_rows[matrix[i][j]-1] > 1 or freq_col[matrix[j][i]-1] > 1) return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for(int k = 0; k < n; ++k) {

        VVI matrix(9, VI(9));
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) cin >> matrix[i][j];
        }
        
        if(/*rows_columns(matrix) and*/ squares(matrix)) cout << "yes\n";
        else cout << "no\n";
    }
}