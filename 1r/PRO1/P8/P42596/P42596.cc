#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> Matrix;

void min_max(const Matrix& mat, int& minimum, int& maximum) {
    maximum = mat[0][0], minimum = mat[0][0];

    for(int i = 0; i < mat.size(); ++i) {
        for(int j = 0; j < mat[0].size(); ++j) {
            maximum = max(maximum, mat[i][j]);
            minimum = min(minimum, mat[i][j]);
        }
    }
}

int main() {
    int n, m;
    int diff = -1;
    int num = 0;
    int temp = 1;

    while(cin >> n >> m) {
        Matrix mat(n, VI(m));
        int maximum, minimum;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> mat[i][j];
            }
        }
        min_max(mat, minimum, maximum);

        int temp_diff = maximum - minimum;

        if(diff < temp_diff) {
            num = temp;
            diff = temp_diff;
        }
        ++temp;
    }
    cout << "la diferencia maxima es " << diff << endl;
    cout << "la primera matriu amb aquesta diferencia es la " << num << endl;
}