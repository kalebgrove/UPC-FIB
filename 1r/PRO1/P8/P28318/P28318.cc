#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > VVI;
typedef vector<int> VI;

void row(const VVI& matrix, int m) {
    int x;
    cin >> x;
    cout << "row " << x << ':';
    for(int i = 0; i < m; ++i) cout << ' ' << matrix[x-1][i];
}

void column(const VVI& matrix, int n) {
    int x;
    cin >> x;
    cout << "column " << x << ':';
    for(int i = 0; i < n; ++i) cout << ' ' << matrix[i][x-1];
}

void element(const VVI& matrix) {
    int x, y;
    cin >> x >> y;
    cout << "element " << x << ' ' << y << ": " << matrix[x-1][y-1];
}

int main() {
    int n, m;
    cin >> n >> m;

    VVI matrix(n, VI(m));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) cin >> matrix[i][j];
    }

    string s; 
    while(cin >> s) {
        if(s == "row") row(matrix, m);
        else if(s == "column") column(matrix, n);
        else if(s == "element") element(matrix);
        cout << endl;
    }
}