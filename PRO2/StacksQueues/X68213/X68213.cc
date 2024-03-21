/* Biblioteca

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void rmv(vector<stack<string>>& v, int cat, int num) {
    for(int i = 0; i < num; ++i) {
        v[cat-1].pop();
    }
}

void print(vector<stack<string>> v, int cat) {
    cout << "Pila de la categoria " << cat << endl;
    while(v[cat-1].size() > 0) {
        cout << v[cat-1].top() << endl;
        v[cat-1].pop();
    }
}

int main() {
    int n;
    cin >> n;

    vector<stack<string>> v(n);

    int op;
    string title;
    int cat, num;

    while(cin >> op and op != -4) {
        
        switch(op) {
            case -1:
                cin >> title >> cat;
                v[cat-1].push(title);
                break;

            case -2:
                cin >> num >> cat;
                rmv(v, cat, num);
                break;
            
            case -3:
                cin >> cat;
                print(v, cat);
                cout << endl;
                break;

            default: break;
        }
    }
}