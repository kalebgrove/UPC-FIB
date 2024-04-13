#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> VC;
typedef vector<vector<char> > VVC;

//We have a matrix with n rows and m columns, therefore, we need to analyze the rows and then the columns, to see the amount of happy faces.

int rows(int n, VVC& matrix, int m) {
    int happy = 0;
    for(int i = 0; i < m; ++i) { //This loop will analyze the each column from the row that is passed by reference.
        if(matrix[n][i] == ':') {
            if(i+1 < m and matrix[n][i+1] == '-') {
                if(i+2 < m and matrix[n][i+2] == ')') ++happy;
            }
        } else if(matrix[n][i] == '(') {
            if(i+1 < m and matrix[n][i+1] == '-') {
                if(i+2 < m and matrix[n][i+2] == ':') ++happy;
            }
        }
    }
    return happy;
}

int columns(int m, VVC& matrix, int n) {
    int happy = 0;
    for(int i = 0; i < n; ++i) { //This loop will analyze the each row from the column that is passed by reference.
        if(matrix[i][m] == '"') {
            if(i+1 < n and matrix[i+1][m] == '|') {
                if(i+2 < n and matrix[i+2][m] == 'v') ++happy;
            }
        } else if(matrix[i][m] == '^') {
            if(i+1 < n and matrix[i+1][m] == '|') {
                if(i+2 < n and matrix[i+2][m] == '"') ++happy;
            }
        }
    }
    return happy;
}

int main() {
    int n, m;
    
    while(cin >> n >> m){    
        VVC matrix(n, VC(m));

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) cin >> matrix[i][j];
        }
        int happy_rows = 0, happy_columns = 0; //Counter for happy faces.
        for(int i = 0; i < n; ++i) { //Loop for the happy faces in the rows.
            happy_rows += rows(i, matrix, m);
        }

        for(int i = 0; i < m; ++i) { //Loop for the happy faces in the columns.
            happy_columns += columns(i, matrix, n);
        }
        cout << happy_rows + happy_columns << endl;}
}