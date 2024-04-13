#include <iostream>

using namespace std;

int main() {
    string s;
    int count = 1;
    string s2 = "";
    
    while(cin >> s and s != ".") {
        if(count%2 == 1) s2 = s + "\n" + s2;
        ++count;
    }
    cout << s2;
}