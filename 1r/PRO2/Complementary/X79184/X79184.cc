/* Aniversaris

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>
#include <map>

using namespace std;

int main() {
    string operation;
    map<string, int> people;
    map<int, int> ages;

    while(cin >> operation) {

        if(operation == "NEWPERSON") {
            string name;
            cin >> name;

            int age;
            cin >> age;

            people[name] = age;
            ages[age] += 1;
        }
        else if(operation == "BIRTHDAY") {
            string name;
            cin >> name;

            map<int, int>::iterator it = ages.find(people[name]);
            if(it -> second == 1) {
                ages.erase(it);
            } else {
                ages[people[name]]--;
            }

            people[name]++;
            ages[people[name]]++;
        }
        else if(operation == "NUMBERWITHAGE") {
            int age;
            cin >> age;

            cout << ages[age] << endl;
        }
        else if(operation == "PEOPLEWITHAGE") {
            int age;
            cin >> age;

            map<string, int>::iterator it = people.begin();
            bool space = false;

            while(it != people.end()) {
                if(it -> second == age) {
                    if(space) cout << ' ';
                    cout << it -> first;
                    space = true;
                }
                ++it;
            }

            /*while(it != people.end() and it -> second != age) {
                ++it;
            }
            if(it != people.end()) cout << it-> first;
            ++it;
            while(it != people.end()) {
                if(it -> second == age) cout << ' ' << it -> first;
                ++it;
            }
            */cout << endl;
        }
    }
}