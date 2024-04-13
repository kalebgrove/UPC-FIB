#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int dtd;        // double triple-double
    int td;         // triple-double (which are not double triple-double)
};

// Pre: p >= 0; in the input is available a name followed by the five statistical categories in p games
// Post: player is conveniently initialized with the input data
void read_player(int p, Player& player) {
    int pts, reb, ass, st, bs;
    player.dtd = 0, player.td = 0;
    for(int i = 0; i < p; ++i) {
        int ctr_dtd = 0, ctr_td = 0;
        cin >> pts >> reb >> ass >> st >> bs;
        if(pts > 9) {
            if(pts > 19) ++ctr_dtd;
            ++ctr_td;
        }
        if(reb > 9) {
            if(reb > 19) ++ctr_dtd;
            ++ctr_td;
        }
        if(ass > 9) {
            if(ass > 19) ++ctr_dtd;
            ++ctr_td;
        }
        if(st > 9) {
            if(st > 19) ++ctr_dtd;
            ++ctr_td;
        }
        if(bs > 9) {
            if(bs > 19) ++ctr_dtd;
            ++ctr_td;
        }
        if(ctr_dtd > 2) ++player.dtd;
        else if(ctr_td > 2) ++player.td;
    }
}

void print(const vector<Player>& player) {
    for(int i = 0; i < player.size(); ++i) {
        cout << player[i].name << ' ' << player[i].dtd << ' ' << player[i].td << endl;
    }
}

bool comp(Player player1, Player player2) {
    if(player1.dtd != player2.dtd) return player1.dtd > player2.dtd;
    if(player1.td != player2.td) return player1.td > player2.td;
    return player1.name < player2.name;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Player> player(m);
    for(int i = 0; i < m; ++i) {
        cin >> player[i].name;
        read_player(n, player[i]);
    }

    sort(player.begin(), player.end(), comp);

    print(player);
}