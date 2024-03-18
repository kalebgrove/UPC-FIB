#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > VVI;
typedef vector<int> VI;
typedef vector<vector<bool> > VVB;
typedef vector<bool> VB;



void search(VVB& checked_matrix, int pos_i, int pos_j) {
    int i = pos_i, j = pos_j;
    while(j < checked_matrix[pos_i].size() and not checked_matrix[pos_i][j]) ++j;
    int end_j = j - 1;

    while(i < checked_matrix.size() and not checked_matrix[i][pos_j]) {
        for(int k = pos_j; k <= end_j; ++k) checked_matrix[i][k] = true;
        ++i;
    }
}

int read_matrix(VVB& checked_matrix, const VVI& matrix) {
    int ctr = 0;
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = 0; j < matrix[0].size(); ++j) {
            if(not checked_matrix[i][j]) {
                ++ctr;
                search(checked_matrix, i, j);
            }
        }
    }
    return ctr;
}

int main() {
    int n, m;

    while(cin >> n >> m){
        VVI matrix(n, VI(m));
        VVB checked_matrix(n, VB(m));

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> matrix[i][j];
                checked_matrix[i][j] = (matrix[i][j] == 0); //Checked matrix will have true in positions that contain 0.
            }
        }
        cout << read_matrix(checked_matrix, matrix) << endl;
    }
}