#include <iostream>

using namespace std;

//Pre: given k > 0 and c multiple characters.
//Post: returns c (char) shifted k places to the right in uppercase.
char encoded(char c, int k) {
    if(c <= 'z' and c >= 'a') {
        return 'A' + (-'a' + c + k)%26;
    }
    else if(c == '_') return ' ';
    return c;
}

int main() {
    char c;
    int k;
    
    while(cin >> k) {
        while(cin >> c and c != '.') {
            cout << encoded(c, k);
        }
        cout << endl;
    }
}