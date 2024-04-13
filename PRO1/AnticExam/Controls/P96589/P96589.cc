#include <iostream>

using namespace std;

int main() {
    char c;
    cin >> c;
    string s;

    if('0' <= c and c <= '9') s = "digit";
    else if('A' <= c and c <= 'z') s = "lletra";
    else s = "res";

    cout << s << endl;
}