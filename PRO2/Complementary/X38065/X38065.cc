/* Nombre de persones amb monedes

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<int, int> coins;
    map<string, int> people;

    string s;

    while(cin >> s) {

        if(s == "NUMPEOPLE") {
            int cns;
            cin >> cns;

            map<int, int>::iterator it = coins.find(cns);
            if(it != coins.end()) cout << it -> second << endl;
            else cout << 0 << endl;

        } else if(s == "DELETE") {
            string name;
            cin >> name;

            map<string, int>::iterator it = people.find(name);
            coins[it -> second]--;
            people.erase(it);

        } else if(s == "ADD") {
            string name;
            cin >> name;

            int amount;
            cin >> amount;

            people[name] = amount;
            coins[amount]++;
        }
    }
}