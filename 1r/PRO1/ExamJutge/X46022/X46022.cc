/* How many games does each person win? (PRO1)

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Player{
    string name;
    int lvl;
    int matcheswon;
    int pos;
};

bool comp(Player a, Player b) {
    if(a.lvl != b.lvl) return a.lvl > b.lvl;
    return a.name < b.name;
}

bool comp2(Player a, Player b) {
    return a.pos < b.pos;
}

int main() {
    int n;
    while(cin >> n) {

        vector<Player> usa_pl(n);
        vector<Player> rus_pl(n);
        
        for(int i = 0; i < n; ++i) {
            cin >> usa_pl[i].name >> usa_pl[i].lvl;
            usa_pl[i].matcheswon = 0;
            usa_pl[i].pos = i;
        }

        for(int i = 0; i < n; ++i) {
            cin >> rus_pl[i].name >> rus_pl[i].lvl;
            rus_pl[i].matcheswon = 0;
            rus_pl[i].pos = i;
        }

        sort(usa_pl.begin(), usa_pl.end(), comp);
        sort(rus_pl.begin(), rus_pl.end(), comp);

        int j = 0;
        int temp = 0, equals = 0;
        for(int i = 0; i < n; ++i) {
            j = temp - equals;
            temp = 0;
            equals = 0;
            while(j < n and usa_pl[i].lvl <= rus_pl[j].lvl) {
                if(usa_pl[i].lvl == rus_pl[j].lvl) {
                    usa_pl[i].matcheswon += 1;
                    ++equals;
                }
                ++j;
            }
            if(j < n) usa_pl[i].matcheswon += (n-j)*2;
            temp = j;
        }

        j = 0;
        temp = 0, equals = 0;
        for(int i = 0; i < n; ++i) {
            j = temp - equals;
            temp = 0;
            equals = 0;
            while(j < n and rus_pl[i].lvl <= usa_pl[j].lvl) {
                if(usa_pl[j].lvl == rus_pl[i].lvl) {
                    rus_pl[i].matcheswon += 1;
                    ++equals;
                }
                ++j;
            }
            if(j < n) rus_pl[i].matcheswon += (n-j)*2;
            temp = j;
        }

        sort(usa_pl.begin(), usa_pl.end(), comp2);
        sort(rus_pl.begin(), rus_pl.end(), comp2);

        cout << usa_pl[0].name << ' ' << usa_pl[0].matcheswon;
        for(int i = 1; i < n; ++i) {
            cout <<  ' ' << usa_pl[i].name << ' ' << usa_pl[i].matcheswon;
        }
        cout << endl;
        
        cout << rus_pl[0].name << ' ' << rus_pl[0].matcheswon;
        for(int i = 1; i < n; ++i) {
            cout << ' ' << rus_pl[i].name << ' ' << rus_pl[i].matcheswon;
        }
        cout << endl;
        cout << endl;
    }
}