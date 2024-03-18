#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > Matrix;

void swap(int& x, int& y) {
    int temp = x; 
    x = y;
    y = temp;
}

void transpose(Matrix& m) {
    for(int i = 0; i < m.size(); ++i) {
        for(int j = 0; j < i; ++j) swap(m[i][j], m[j][i]);
    }
}