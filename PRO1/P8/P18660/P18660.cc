#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char> > VVC;
typedef vector<char> VC;
typedef vector<string> VS;

char uppercase(char c) {
    char upper = c - 'a' + 'A';
    return upper;
}

void row(VVC& new_matrix, const VVC& matrix, string& name, int i, int j, int y) {
    if(j + name.size() > y) return;
    int k = 0;
    while(k < name.size() and matrix[i][j+k] == name[k]) ++k;
    if(k == name.size()) {
        for(int l = 0; l < k; ++l) new_matrix[i][j+l] = uppercase(name[l]);
    }
}

void column(VVC& new_matrix, const VVC& matrix, string& name, int i, int j, int z) {
    if(i + name.size() > z) return;
    int k = 0;
    while(k < name.size() and matrix[i+k][j] == name[k]) ++k;
    if(k == name.size()) {
        for(int l = 0; l < k; ++l) new_matrix[i+l][j] = uppercase(name[l]);
    }
}

void diagonal(VVC& new_matrix, const VVC& matrix, string& name, int i, int j) {
    if(i + name.size() > matrix.size() or j + name.size() > matrix[0].size()) return;
    int ctr = 0;
    while(ctr < name.size() and matrix[i+ctr][j+ctr] == name[ctr]) ++ctr;
    if(ctr == name.size()) {
        for(int k = 0; k < name.size(); ++k) new_matrix[i+k][j+k] = uppercase(name[k]);
    }
}

void print(VVC& new_matrix, int y, int z) {
    for(int i = 0; i < y; ++i) {
        cout << new_matrix[i][0];
        for(int j = 1; j < z; ++j) cout << ' ' << new_matrix[i][j];
        cout << endl;
    }
}

void caller(VVC& new_matrix, const VVC& matrix, string& name, int y, int z) {
    for(int i = 0; i < y; ++i) {
        for(int j = 0; j < z; ++j) {
            row(new_matrix, matrix, name, i, j, y);
            column(new_matrix, matrix, name, i, j, z);
            diagonal(new_matrix, matrix, name, i, j);
        }
    }
}

void initial_function(const VVC& matrix, VS& names, int y, int z) {
    VVC new_matrix = matrix;
    for(int i = 0; i < names.size(); ++i) {
        caller(new_matrix, matrix, names[i], y, z);
    }
    print(new_matrix, y, z);
}

int main() {
    int x, y, z;
    int count = 0;

    while (cin >> x >> y >> z) {

        VS names(x);
        for(int i = 0; i < x; ++i) cin >> names[i];

        VVC matrix(y, VC(z));
        for(int i = 0; i < y; ++i) {
            for(int j = 0; j < z; ++j) cin >> matrix[i][j];
        }
        if(count > 0) cout << endl;
        initial_function(matrix, names, y, z);
        ++count;
    }
}