#include <iostream>

using namespace std;

int main() {
    char c; 
    int a = 0, b = 0, c_ = 0, d = 0;
    bool found = false;
    int cnt = 0;
    cin >> c;

    while(not found) {
        if(c == 'a') ++a;
        else if(c == 'b') ++b;
        else if(c == 'c') ++c_;
        else if(c == 'd') ++d;

        if(a == 2 or b == 2 or c_ == 2 or d == 2) {
            found = true;
        } else {
            ++cnt;
            cin >> c;
        }
    }
    cout << c << ' ' << cnt << endl;
}