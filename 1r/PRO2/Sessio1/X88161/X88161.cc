/* Classificació de la lliga

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<pair<int, int>> VP;
typedef vector<VP> Matrix;

/* In the matrix, the i position is the away goals for the team. The home goals are those such that i = j, in the sense that they share the same value, not position.
In this position, where i == j, the result is irrelevant: it corresponds to the diagonal, that indicated that the team played itself.*/

struct team {
    int pos;
    int pts; //If they win, they get 3 pts, 1 pt if it's a tie and 0 pts if its a loss.
    int g_f; //Goals for.
    int g_a; //Goals against.
};

void read_matrix(Matrix& results) {
    int n = int(results.size());

    pair<int, int> x;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> x.first >> x.second;
            results[i][j] = x;
        }
    }
}

void analyze_matrix(const Matrix& results, vector<team>& teams) {
    int n = int(results.size());


    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i != j) {

                teams[i].g_f += results[i][j].first;
                teams[i].g_a += results[i][j].second;

                teams[j].g_f += results[i][j].second;
                teams[j].g_a += results[i][j].first;

                if(results[i][j].first > results[i][j].second) teams[i].pts += 3;
                else if(results[i][j].first == results[i][j].second) {
                    teams[i].pts += 1;
                    teams[j].pts += 1;
                } else {
                    teams[j].pts += 3;
                }
            }
        }
    }
}

bool comp(team t1, team t2) {
    if(t1.pts != t2.pts) return t1.pts > t2.pts;
    if((t1.g_f - t1.g_a) != (t2.g_f - t2.g_a)) return (t1.g_f - t1.g_a) > (t2.g_f - t2.g_a);
    return t1.pos < t2.pos;
}

void print(const vector<team>& teams) {
    int n = int(teams.size());
    
    for(int i = 0; i < n; ++i) {
        cout << teams[i].pos << ' ' << teams[i].pts << ' ' << teams[i].g_f << ' ' << teams[i].g_a << endl;
    }
}

int main() {
    int n; //Dimensions of the square matrix;
    cin >> n;

    Matrix results(n, VP(n));
    read_matrix(results);

    vector<team> teams(n);

    for(int i = 0; i < n; ++i) {
        teams[i].pts = 0;
        teams[i].g_f = 0;
        teams[i].g_a = 0;
        teams[i].pos = i+1;
    }

    analyze_matrix(results, teams);

    sort(teams.begin(), teams.end(), comp);

    print(teams);
    
}