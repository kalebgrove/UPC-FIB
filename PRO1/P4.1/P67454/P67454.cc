#include <iostream>

using namespace std;

int main() {
    char c;
    int cnt = 0;

    while(cin >> c and c != '.') {
        if(c == 'a') ++cnt;
    }
    cout << cnt << endl;
}