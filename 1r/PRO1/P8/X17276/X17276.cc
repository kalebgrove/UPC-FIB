#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int> > VVI;
typedef vector<int> VI;

void coordinates(int& c_x, int& c_y, int pos_i, int pos_j, int n) {
    if(n == 1) {
        c_x = pos_i + 1;
        c_y = pos_j + 1;
    } else if(n == 2) {
        c_x = pos_i - 1;
        c_y = pos_j - 1;
    } else if(n == 3) {
        c_x = pos_i + 1;
        c_y = pos_j - 1;
    } else {
        c_x = pos_i - 1;
        c_y = pos_j + 1;
    }
}

void inc(int& c_x, int& c_y, int n) {
    if(n == 1) {
        ++c_x;
        ++c_y;
    } else if(n == 2) {
        --c_x;
        --c_y;
    } else if(n == 3) {
        ++c_x;
        --c_y;
    } else {
        --c_x;
        ++c_y;
    }
}

void diagonals(const VVI& matrix, int pos_i, int pos_j) {
    int ctr = 1, end_ctr = 0;
    int c_x, c_y;
    
    while(ctr < 5) {
        coordinates(c_x, c_y, pos_i, pos_j, ctr);
        bool end = false;
        int num1 = matrix[pos_i][pos_j];

        while(c_x < matrix.size() and c_y < matrix[0].size() and c_x >= 0 and c_y >= 0 and not end) {
            int num2 = matrix[c_x][c_y];
            if(num1 >= num2) {
                end = true;
                ++end_ctr;
            }
            num1 = num2;
            inc(c_x, c_y, ctr);            
        }
        ++ctr;
    }
    if(end_ctr == 0) cout << "yes\n";
    else cout << "no\n";
}

int main() {
    int n, m;

    while(cin >> n >> m) {
        VVI matrix(n, VI(m));
        for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) cin >> matrix[i][j];
            }

        int x, y;
        cin >> x >> y;
        diagonals(matrix, x, y);
    }
}