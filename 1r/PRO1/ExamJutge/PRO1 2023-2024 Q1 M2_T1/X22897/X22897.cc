#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI > VVI;

void xbyx_counter(const VVI& v) {
    int cnt = 0;
    int n = v.size();
    int m = v[0].size();
    VVI sub_matrix(n, VI(m));

    for(int i = 0; i < v.size(); ++i) {
        for(int j = 0; j < v[0].size(); ++j) {
            if(i == 0 or j == 0 or v[i][j] != v[i][j-1] or v[i][j] != v[i-1][j] or v[i][j] != v[i-1][j-1]) {
                sub_matrix[i][j] = 1;
            } else {
                sub_matrix[i][j] = 1 + min(sub_matrix[i-1][j-1], min(sub_matrix[i][j-1], sub_matrix[i-1][j]));
            }
            cnt += sub_matrix[i][j];
        }
    }
    cout << cnt << endl;
}

int main() {
    int n, m;
    char c;

    while(cin >> n >> m) {
        VVI v(n, VI(m));

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> c;
                v[i][j] = int(c - '0');
            }
        }
        xbyx_counter(v);
    }
}