/* Canviar paréntesis i corxets de tancar per a produïr una seqüència ben parentitzada

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>
#include <list>
#include <stack>
#include <queue>

using namespace std;

void insert_s(string& s, stack<char>& s1, stack<char>& s2) {
    int n = s.size();

    s1.push(s[0]);

    for(int i = n-1; i > 0; i--) {
        s2.push(s[i]);
    }
}

int main() {
    stack<char> s1;
    stack<char> s2;

    string s;
    while(cin >> s){
        insert_s(s, s1, s2);

        int n = 0;
        while(not s2.empty()) {
            char x = s1.top();
            char y = s2.top();

            //cout << x << ' ' << y << endl;

            if(x == '(' and y == ')') {
                s1.pop();
                s2.pop();
            } else if(x == '(' and y == ']') {
                n++;
                s1.pop();
                s2.pop();
            } else if(x == '[' and y == ']') {
                s1.pop();
                s2.pop();
            } else if(x == '[' and y == ')') {
                n++;
                s1.pop();
                s2.pop();
            } else {
                s1.push(y);
                s2.pop();
            }

            if(s1.empty() and not s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
            //cout << "n " << n << endl;
        }
        cout << n << endl;
    }
}