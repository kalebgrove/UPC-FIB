/* Indicar seqüències ben parentitzades

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>
#include <stack>

using namespace std;

int main() {
    string s;

    stack<int> paren;

    while(cin >> s) {
        int pos = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') {
                ++pos;
                paren.push(pos);
                cout << '(' << pos;
            }
            else {
                cout << ')' << paren.top();
                paren.pop();
            }
        }
        cout << endl;
    }
}