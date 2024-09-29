#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct Attributes
{
    string name;
    int elo;
};

bool comp(Attributes player1, Attributes player2)
{
    if (player1.elo != player2.elo)
        return player1.elo > player2.elo;
    else
        return player1.name < player2.name;
}

int main()
{
    map<string, int> index;
    vector<Attributes> players_elo;
    set<string> loggedin;

    string op;
    int i = 0;

    while (cin >> op)
    {

        if (op == "LOGIN")
        {
            string name;
            cin >> name;

            if (loggedin.count(name) > 0)
            {
            }
            else
            {
                loggedin.insert(name);

                if (index.count(name) < 1)
                {
                    index[name] = i;
                    ++i;

                    Attributes player;
                    player.name = name;
                    player.elo = 1200;

                    players_elo.push_back(player);
                }
            }
        }
        else if (op == "LOGOUT")
        {
            string name;
            cin >> name;

            if (loggedin.count(name) > 0)
            {
                loggedin.erase(name);
            }
        }
        else if (op == "PLAY")
        {
            string name1, name2;
            cin >> name1 >> name2;

            if (loggedin.count(name1) < 1 or loggedin.count(name2) < 1)
            {
                cout << "player(s) not connected" << endl;
            }
            else
            {
                // name1 beats name2
                players_elo[index[name1]].elo += 10;

                if (players_elo[index[name2]].elo > 1200)
                    players_elo[index[name2]].elo -= 10;
            }
        }
        else if (op == "GET_ELO")
        {
            string name;
            cin >> name;

            cout << name << ' ' << players_elo[index[name]].elo << endl;
        }
    }

    cout << endl;

    cout << "RANKING" << endl;

    sort(players_elo.begin(), players_elo.end(), comp);

    int n = players_elo.size();

    for (int j = 0; j < n; ++j)
    {
        cout << players_elo[j].name << ' ' << players_elo[j].elo << endl;
    }
}