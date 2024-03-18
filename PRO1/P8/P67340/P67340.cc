#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char> > VVC;
typedef vector<char> VC;
typedef vector<vector<bool> > VVB;
typedef vector<bool> VB;

void coordinate(int& c_x, int& c_y, int pos_i, int pos_j, int n) {
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

void exes2(VVB& has_X, int pos_i, int pos_j) {
    int ctr = 1;
    int c_x, c_y;
    while(ctr < 5) {
        coordinate(c_x, c_y, pos_i, pos_j, ctr);
        bool found = false;
        while(c_x < has_X.size() and c_y < has_X[0].size() and c_x >= 0 and c_y >= 0 and not found) {

            if(has_X[c_x][c_y]) {
                cout << '(' << pos_i+1 << ',' << pos_j+1 << ")<->(" << c_x+1 << ',' << c_y+1 << ")\n";
                found = true;
            }
            
            if(ctr == 1) {
                ++c_x;
                ++c_y;
            } else if(ctr == 2) {
                --c_x;
                --c_y;
            } else if(ctr == 3) {
                ++c_x;
                --c_y;
            } else {
                --c_x;
                ++c_y;
            }
        }
        ++ctr;
    }
}


/*void exes(VVB& has_X, int pos_i, int pos_j) {
    int c_x = pos_i + 1, c_y = pos_j + 1;
    bool found = false;
    while(c_x < has_X.size() and c_y < has_X[0].size() and not found) {
        if(has_X[c_x][c_y]) {
            cout << '(' << pos_i+1 << ',' << pos_j+1 << ")<->(" << c_x+1 << ',' << c_y+1 << ")\n";
            found = true;
        }
        ++c_x;
        ++c_y;
    }
    
    c_x = pos_i - 1, c_y = pos_j - 1;
    found = false;
    while(c_x >= 0 and c_y >= 0 and not found) {
        if(has_X[c_x][c_y]) {
            cout << '(' << pos_i+1 << ',' << pos_j+1 << ")<->(" << c_x+1 << ',' << c_y+1 << ")\n";
            found = true;
        }
        --c_x;
        --c_y;
    }

    c_x = pos_i + 1, c_y = pos_j - 1;
    found = false;
    while(c_x < has_X.size() and c_y >= 0 and not found) {
        if(has_X[c_x][c_y]) {
            cout << '(' << pos_i+1 << ',' << pos_j+1 << ")<->(" << c_x+1 << ',' << c_y+1 << ")\n";
            found = true;
        }
        ++c_x;
        --c_y;
    }

    c_x = pos_i - 1, c_y = pos_j + 1;
    found = false;
    while(c_x >= 0 and c_y < has_X[0].size() and not found) {
        if(has_X[c_x][c_y]) {
            cout << '(' << pos_i+1 << ',' << pos_j+1 << ")<->(" << c_x+1 << ',' << c_y+1 << ")\n";
            found = true;
        }
        --c_x;
        ++c_y;
    }
}*/

void search(VVB& has_X) {
    for(int i = 0; i < has_X.size(); ++i) {
        for(int j = 0; j < has_X[0].size(); ++j) {
            if(has_X[i][j]) exes2(has_X, i, j);
        }
    }
}

int main() {
    int n, m;

    cin >> n >> m;

    VVC matrix(n, VC(m));
    VVB has_X(n, VB(m,0));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
            has_X[i][j] = (matrix[i][j] == 'X');
        }
    }
    search(has_X);
}