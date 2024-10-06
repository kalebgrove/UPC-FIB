#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;


string c;

struct Compare {
    bool operator()(const string& a, const string& b) {
        if(a.size() == b.size()) {
            string m = c.substr(0, a.size());
            if(a == m) return false;
            else if(b == m) return true;
            else if(a < b) {
                if (a < m and b > m) return true;
                return false;
            } else {
                if(b < m and a > m) return false;
                return true;
            }
        }
        return a.size() > b.size();
    }
};


int main() {
    string first;

    priority_queue<string, vector<string>, Compare> supporters;

    int tickets = 0;

    string op;
    while(cin >> op) {

        if(op == "S") {
            string name;
            cin >> name;

            supporters.push(name);

            while(tickets > 0 and !supporters.empty()) {
                cout << supporters.top() << endl;
                supporters.pop();
                --tickets;
            }
        } else if(op == "T") {
            if(!supporters.empty()) {
                cout << supporters.top() << endl;
                supporters.pop();
            }
            else {
                ++tickets;
            }
        } else if(op == "E") {
            cout << tickets << " ticket(s) left" << endl;
            cout << supporters.size() << " supporter(s) with no ticket" << endl;

            cout << endl;

            supporters = priority_queue<string, vector<string>, Compare> ();
            tickets = 0;
        }
        else {
            c = op;
        }
    }
}