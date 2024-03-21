/* Queues of a supermarket (1)

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    cin.ignore();

    vector<queue<string> > v(n);

    for(int i = 0; i < n; ++i) {
        string s;
        getline(cin,s);

        stringstream ss(s);

        string names;
        while(ss >> names) v[i].push(names);
    }

    cout << "DEPARTS" << endl;
    cout << "-------" << endl;

    string op;
    int q;
    string name;
    while(cin >> op) {
        if(op == "LEAVES") {
            cin >> q;
            if(q > 0 and q <= n) {
                if(not v[q-1].empty()) {
                    cout << v[q-1].front() << endl;
                    v[q-1].pop();
                }
            }
        } else {
            cin >> name >> q;
            if(q > 0 and q <= n) v[q-1].push(name);
        }
    }
    cout << endl;

    cout << "FINAL CONTENTS" << endl;
    cout << "--------------" << endl;

    for(int i = 0; i < n; ++i) {
        cout << "queue " << i+1 << ':';
        while(v[i].size() > 0) {
            cout << ' ' << v[i].front();
            v[i].pop();
        }
        cout << endl;
    }
}