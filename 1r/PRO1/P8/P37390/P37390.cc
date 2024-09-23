#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > Matrix;

Matrix product(const Matrix& a, const Matrix& b) {
    int n = a.size(); //Since it's the product of square matrices, then the size of both is the same.
    Matrix c(a.size(),(vector<int>(a.size(), 0)));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int l = 0; l < n; ++l) {
                c[i][j] += a[i][l]*b[l][j];
            }
        }
    }
    return c;
}