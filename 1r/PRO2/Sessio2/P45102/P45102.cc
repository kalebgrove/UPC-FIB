/* Completely parenthesized expression

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>

using namespace std;

int parenthesis() {
    char c;
    cin >> c;

    int num1, num2;

    //Base case:
    if(int('0') <= int(c) and int(c) <= int('9')) return int(c) - int('0');
    //Magical cases:
    else{
        num1 = parenthesis();
        char op;
        cin >> op;
        num2 = parenthesis();
        char paren_closed;
        cin >> paren_closed;
        if(op == '+') {
            return num1+num2;
        } else if(op == '-') {
            return num1-num2;
        } else {
            return num1*num2;
        }
    }
}

int main() {
    cout << parenthesis() << endl;
}