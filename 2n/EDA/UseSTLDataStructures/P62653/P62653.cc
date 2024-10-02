#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool comp(string &a, string &b) {
    if(a.size() != b.size()) {
        return a.size() > b.size();
    }
    //If they're the same size, we want the one that comes before in lexicographic order to be second, so that the vector "starts" from the back.
    return a > b;
}

int main() {
    string first;

    while(cin >> first) {    
        int tickets = 0;

        vector<string> before;
        vector<string> after;

        char op;
        while(cin >> op and op != 'E') {

            if(op == 'T') {
                ++tickets;

                if(!before.empty()) {
                    sort(before.begin(), before.end(), comp);

                    sort(after.begin(), after.end(), comp);

                    while(!before.empty() and !after.empty() and tickets > 0) {
                        if(before.back().size() < after.back().size()) {
                            cout << before.back() << endl;
                            before.pop_back();
                        } else if(before.back().size() > after.back().size()) {
                            cout << after.back() << endl;
                            after.pop_back();
                        } else {
                            cout << after.back() << endl;
                            after.pop_back();
                        }

                        --tickets;
                    }

                    while(!before.empty() and tickets > 0) {
                        cout << before.back() << endl;
                        before.pop_back();
                        --tickets;
                    }

                    while(!after.empty() and tickets > 0) {
                        cout << after.back() << endl;
                        after.pop_back();
                        --tickets;
                    }
                }


            } else if(op == 'S') {
                string name;
                cin >> name;

                //Name is larger than first means it comes afterwards.
                if(name >= first.substr(0, name.size())) {
                    after.push_back(name);
                } else {
                    before.push_back(name);
                }
            }
        }

        cout << tickets << " ticket(s) left" << endl;
        cout << before.size() + after.size() << " supporter(s) with no ticket" << endl;

        cout << endl;
    }
}