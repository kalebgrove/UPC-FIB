/* Patró recursiu

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef vector<bool> VB;
typedef vector<VB> Matrix;

void recursive(Matrix& mat, int x1, int y1, int x2, int y2) {
    int x_mid = 0;
    int y_mid = 0;
    //Base case:
    if(x1 == x2 and y1 == y2) mat[x1][y1] = false;
    else {
        x_mid = (x1+x2)/2;
        y_mid = (y1+y2)/2;
        mat[x_mid][y1] = false;
        mat[x_mid][y2] = false;
        mat[x1][y_mid] = false;
        mat[x2][y_mid] = false;

        //top-left:
        recursive(mat, x1, y1, x_mid-1, y_mid-1);

        //top-right:
        recursive(mat, x1, y_mid+1, x_mid-1, y2);

        //bottom-left:
        recursive(mat, x_mid+1, y1, x2, y_mid-1);

        //bottom-right:
        recursive(mat, x_mid+1, y_mid+1, x2, y2);
    }

}

int main() {
    int n;
    cin >> n;

    //False will hold the characters # and true will hold the characters .
    Matrix mat(pow(2,n)-1, VB(pow(2,n)-1, true));

    recursive(mat, 0, 0, pow(2,n)-2, pow(2,n)-2);

    for(int i = 0; i < pow(2,n)-1; ++i) {
        for(int j = 0; j < pow(2, n)-1; ++j) {
            if(mat[i][j]) cout << '.';
            else cout << '#';
        }
        cout << endl;
    }
}