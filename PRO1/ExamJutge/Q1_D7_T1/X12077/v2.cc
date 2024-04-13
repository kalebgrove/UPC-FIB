#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<char> > matrix(n, vector<char>(m));
        vector<vector<int> > dp(n, vector<int>(m, 0));
        vector<vector<int> > count(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> matrix[i][j];
                if (matrix[i][j] == ':') {
                    dp[i][j] = 1;
                } else if (matrix[i][j] == '-' && i > 0 && j > 0) {
                    dp[i][j] = count[i-1][j-1];
                }
                if (i > 0) {
                    count[i][j] += count[i-1][j];
                }
                if (j > 0) {
                    count[i][j] += count[i][j-1];
                }
                if (i > 0 && j > 0) {
                    count[i][j] -= count[i-1][j-1];
                }
                if (matrix[i][j] == ')' && i > 0 && j > 0) {
                    count[i][j] += dp[i-1][j-1];
                }
            }
        }
        cout << count[n-1][m-1] << endl;
    }
    return 0;
}
