#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<int> VI;
typedef vector<VI> VVI;

int value(const VVI& v, int x, int y) {
    return v[x][y];
}

void horizontal(const VVC& c, const VVI& v, string s, int i, int j, int& maximum_h) {
    if(j + s.size() > c[0].size()) return;
    int sum = 0;
    int k = 0;
    while(j+k < c[0].size() and c[i][j+k] == s[k]) {
        sum += value(v, i, j+k);
        ++k;
    }
    if(k == s.size()) maximum_h = max(maximum_h, sum);
}

void vertical(const VVC& c, const VVI& v, string s, int i, int j, int& maximum_v) {
    if(i + s.size() > c.size()) return;
    int sum = 0;
    int k = 0;
    while(i+k < c.size() and c[i+k][j] == s[k]) {
        sum += value(v, i+k, j);
        ++k;
    }
    if(k == s.size()) maximum_v = max(maximum_v, sum);
}

void search(const VVC& c, const VVI& v, string s, int& maximum_h, int& maximum_v) {
    for(int i = 0; i < c.size(); ++i) {
        for(int j = 0; j < c[0].size(); ++j) {
            horizontal(c, v, s, i, j, maximum_h);
            vertical(c, v, s, i, j, maximum_v);
        }
    }
}

int main(){
    int n, m;
    
    while(cin >> n >> m) {    
        VVC c(n, VC(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) cin >> c[i][j];
        }

        VVI v(n, VI(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) cin >> v[i][j];
        }

        int x;
        cin >> x;
        string s;

        for(int i = 0; i < x; ++i) {
            cin >> s;
            int maximum_h = -1;
            int maximum_v = -1;
            search(c, v, s, maximum_h, maximum_v);
            if(maximum_h != -1 or maximum_v != -1) cout << max(maximum_h, maximum_v) << endl;
            else cout << "no\n";
        }
    }
}