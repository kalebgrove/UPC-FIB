#include <iostream>
#include <vector>
using namespace std;


int happy_face (int n, int m) {
    char c;
    int happy = 0;
    vector<vector<vector<int>>> orden(n+1, vector<vector<int>>(m,vector<int>(2, 0)));
    cin >> c;
    if (c == ':') orden [0][0][0] = 1;
    for (int j = 1; j < m; ++j) {
        cin >> c;
        if (c == ':') orden[0][j][0] = 1;
        orden [0][j][0] += orden [0][j-1][0];
    }


    for (int i = 1; i < n; ++i) {
        cin >> c;
        if (c == ':') orden[i][0][0] = 1; 
        orden [n][0][0] += orden[i-1][0][0];
        orden [n][0][1] += orden[i-1][0][1]; 
        for (int j = 1; j < m; ++j) {
            cin >> c;
            if (c == ':') orden[i][j][0] = 1;
            else if (c == '-') orden [i][j][1] += orden [n][j-1][0];
            else if (c == ')') happy += orden [n][j-1][1];
                
            
            orden [i][j][0] += orden [i][j-1][0];
            orden [i][j][1] += orden [i][j-1][1];
            orden [n][j][0] += orden[i-1][j][0];
            orden [n][j][1] += orden[i-1][j][1];
}
    }
    return happy;
}

int main () {
    int n,m;
    while (cin >> n >> m) {

        if (n > 2  and m > 2) cout << happy_face(n,m) << endl;
        else {
            char c;
            for (int i = 0; i < n;++i) {
                for (int j = 0; j < m; ++j) cin >> c;
            }
            cout << '0' << endl;
        }
    }
}