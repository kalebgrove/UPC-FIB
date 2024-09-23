/* Punt mig d'una llista

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> l;
    list<int>::iterator it = l.begin();

    string op;
    int n;

    while(cin >> op) {

        if(op == "push_back") {
            cin >> n;
            l.push_back(n);

            if(l.size() == 1) it = l.begin();
            else {
                if(l.size()%2 == 0) it++;
            }

        } else if(op == "push_front") {
            cin >> n;
            l.push_front(n);

            if(l.size() == 1) it = l.begin();
            else {
                if(l.size()%2 == 1) it--;
            }

        } else if(op == "pop_back") {
            if(l.empty()) cout << "error" << endl;
            else {
                if(l.size()%2 == 0) it--;
                l.pop_back();
            }

        } else if(op == "pop_front") {
            if(l.empty()) cout << "error" << endl;
            else {
                if(l.size()%2 == 1) it++;
                l.pop_front();
            }

        } else if(op == "get_mid_value") {
            if(l.size()%2 == 0) cout << "error" << endl;
            else cout << *it << endl;
        }
    }
}
