#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<string> > VVS;
typedef vector<string> VS;

void recursion() {
    
}

int main() {
    VVS matrix{{" | "}, {"-o-"}, {" | "}};

    for(int i = 0; i < matrix.size(); ++i) {
        cout << '|';
        for(int j = 0; j < matrix[0].size(); ++j) cout << matrix[i][j];
        cout << '|' << endl;
    }
}