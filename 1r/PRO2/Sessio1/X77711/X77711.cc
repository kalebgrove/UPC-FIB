/* Classificació de la lliga(2)

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<pair<int, int> > VP;
typedef vector<VP > Matrix;

struct team {
    int pos;
    int pts;
    int g_f, g_a;
};

void read_matrix(Matrix& games) {
    int n = int(games.size());

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 2; ++j) {
            cin >> games[i][j].first >> games[i][j].second;
        }
    }
}

void analyze_matrix(const Matrix& games, vector<team>& teams) {
    int n = int(games.size());

    for(int i = 0; i < n; ++i) {
        if(games[i][1].first > games[i][1].second) {
            teams[games[i][0].first-1 ].pts += 3;

        } else if(games[i][1].first == games[i][1].second) {
            teams[games[i][0].first-1].pts += 1;
            teams[games[i][0].second-1].pts += 1;

        } else {
            teams[games[i][0].second-1].pts += 3;
        }
//--------------------------------------------------- Now we do the goals.
        teams[games[i][0].first-1].g_f += games[i][1].first;
        teams[games[i][0].first-1].g_a += games[i][1].second;

        teams[games[i][0].second-1].g_f += games[i][1].second;
        teams[games[i][0].second-1].g_a += games[i][1].first;
    }
}

bool comp(team t1, team t2) {
    if(t1.pts != t2.pts) return t1.pts > t2.pts;
    if((t1.g_f - t1.g_a) != (t2.g_f - t2.g_a)) return (t1.g_f - t1.g_a) > (t2.g_f - t2.g_a);
    return t1.pos < t2.pos;
}

void prinet_teams(const vector<team>& team) {
    int n = int(team.size());

    for(int i = 0; i < n; ++i) {
        cout << team[i].pos << ' ' << team[i].pts << ' ' << team[i].g_f << ' ' << team[i].g_a << endl;
    }
}

int main() {
    int n, m;
    //n is the number of teams, m is the number of game days, where in each day there is played n/2 games.

    cin >> n >> m;

    int games_per_day = n/2; //Indicates the number of games per day.

    Matrix games(m*games_per_day, VP(2));

    read_matrix(games);

    vector<team> teams(n);

    for(int i = 0; i < n; ++i) {
        teams[i].pos = i+1;
        teams[i].pts = 0;
        teams[i].g_f = 0;
        teams[i].g_a = 0;
    }

    analyze_matrix(games, teams);

    sort(teams.begin(), teams.end(), comp);

    prinet_teams(teams);    
}