#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
    if(a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

int main()
{
    string s;
    int i = 1;

    set<string> HAS;
    set<string> HAD;

    while (cin >> s and s != "QUIT")
    {
        if(s == "END") {
            cout << "GAME #" << i << endl;
            ++i;

            cout << "HAS:" << endl;

            for(set<string>::iterator it = HAS.begin(); it != HAS.end(); ++it) {
                cout << *it << endl;
            }

            cout << endl;

            cout << "HAD:" << endl;

            vector<string> had_ordered;

            for(set<string>::iterator it = HAD.begin(); it != HAD.end(); ++it) {
                had_ordered.push_back(*it);
            }

            sort(had_ordered.begin(), had_ordered.end(), comp);

            for(int j = 0; j < had_ordered.size() ; ++j) {
                cout << had_ordered[j] << endl;
            }

            cout << endl;

            HAS.clear();
            HAD.clear();

        } else if (HAS.count(s) > 0) {
            HAS.erase(s);

            HAD.insert(s);
        } else {
            HAS.insert(s);

            if(HAD.count(s) > 0) HAD.erase(s);
        }
    }
    cout << "GAME #" << i << endl;

    cout << "HAS:" << endl;

    for(set<string>::iterator it = HAS.begin(); it != HAS.end(); ++it) {
        cout << *it << endl;
    }

    cout << endl;

    cout << "HAD:" << endl;

    vector<string> had_ordered;

    for(set<string>::iterator it = HAD.begin(); it != HAD.end(); ++it) {
        had_ordered.push_back(*it);
    }

    sort(had_ordered.begin(), had_ordered.end(), comp);

    for(int j = 0; j < had_ordered.size() ; ++j) {
        cout << had_ordered[j] << endl;
    }
}