#include <iostream>

using namespace std;

int main() {
    char c;
    int pos_x = 0;
    int pos_y = 0;

    while(cin >> c) {
        if(c == 'n') --pos_y;
        if(c == 's') ++pos_y;
        if(c == 'e') ++pos_x;
        if(c == 'w') --pos_x;
    }
    cout << '(' << pos_x << ", " << pos_y << ')' << endl;
}