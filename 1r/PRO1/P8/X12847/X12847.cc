#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<vector<bool> > Board;
typedef vector<char> VC;
typedef vector<VC> VVC;

int distance(const Board& ships, int x, int y) {
    int dist = 100;
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j) {
            if(ships[i][j]) {
                dist = min(dist, max(abs(x-i), abs(y-j)));
            }
        }
    }
    return dist;
}

void print(const Board& ships) {
    cout << " 12345678910\n";

    char c = 'a';

    for(int i = 0; i < 10; ++i) {
        cout << c << ' ';
        for(int j = 0; j < 10; ++j) {
            if(ships[i][j]) cout << 'X';
            else cout << '.';
        }
        cout << endl;
        ++c;
    }
    cout << endl;
}

int main() {
    VVC exes_os(10, VC(10, '.'));
    Board ships(10, vector<bool>(10, false));

    int length;
    char direction;
    string s;

    for(int i = 0; i < 10; ++i) {
        cin >> s >> length >> direction;

        int row = int(s[0] - 'a');
        int col;

        if(s.size() == 2) col = int(s[1] - '1');
        else col = 9;


        if(direction == 'h') {
            for(int j = col; j < col + length; ++j) {
                ships[row][j] = true;
            }
        } else {
            for(int j = row; j < row + length; ++j) {
                ships[j][col] = true;
            }
        }
    }

    print(ships);

    while(cin >> s) {
        int s_row = int(s[0] - 'a');
        int s_col;

        if(s.size() == 2) s_col = int(s[1] - '1');
        else s_col = 10;

        if(ships[s_row][s_col] == true) {
            cout << s << " touched!\n";
            ships[s_row][s_col] = false;
        }
        else {
            cout << s << " water! closest ship at distance " << distance(ships, s_row, s_col) << endl;
        }
    }
}