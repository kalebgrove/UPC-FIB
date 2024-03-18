#include <iostream>

using namespace std;

void reversed(string s) {
    cin >> s;
    if(s != "end"){
        reversed(s);
        cout << s << endl;
        cin >> s;
    }
}

int main() {
    string s;
    reversed(s);
}