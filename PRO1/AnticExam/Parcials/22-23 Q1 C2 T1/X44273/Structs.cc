#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int pts;
};

bool comp(Player player1, Player player2) {
    if(player1.pts != player2.pts) return player1.pts > player2.pts;
    return player1.name < player2.name;
}

int main() {
    int n;
    cin >> n; //Nombre de jugadors en l'input.

    vector<Player> players(n);

    for(int i = 0; i < n; ++i) {
        cin >> players[i].name;
        cin >> players[i].pts;
    }

    sort(players.begin(), players.end(), comp);
}