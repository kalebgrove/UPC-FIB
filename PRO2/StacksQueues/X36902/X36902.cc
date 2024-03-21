/* Avaluació d'una expressió amb parèntesis

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>
#include <stack>

using namespace std;

int main() {
    char c;
    int pos = 0;

    stack<char> s;

    bool end = false;

    while(not end and cin >> c and c != '.') {
        ++pos;
        if(c == '(' or c == '[') {
            s.push(c);
        } else {
            if(not s.empty()) {
                if(c == ')' and s.top() == '(') {
                    s.pop();
                } else if(c == ')' and s.top() == '[') {
                    end = true;
                } else if(c == ']' and s.top() == '[') {
                    s.pop();
                } else {
                    end = true;
                }
            } else {
                end = true;
            }
            
        }
    }

    if(not end and s.size() == 0) cout << "Correcte" << endl;
    else cout << "Incorrecte " << pos << endl;
}