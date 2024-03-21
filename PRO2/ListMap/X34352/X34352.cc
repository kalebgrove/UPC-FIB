/* Freqüència de paraules amb diccionaris

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> m;

    char c;
    while(cin >> c) {
        string s;
        cin >> s;
        if(c == 'a') {
            m[s]++;
        } else if(c == 'f') {
            cout << m[s] << endl;
        }
    }
}