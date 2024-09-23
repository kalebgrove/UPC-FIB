#include <iostream>

using namespace std;

void reversed(string s) {
    if(cin >> s){
        reversed(s);
        cout << s << endl;
    }
}

int main() {
    string s;
    reversed(s);
}