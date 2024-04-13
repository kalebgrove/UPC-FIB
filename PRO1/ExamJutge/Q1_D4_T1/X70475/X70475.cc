#include <iostream>

using namespace std;

int main() {
    int happy = 0, sad = 0;
    char c0, c1;
    cin >> c0;

    while(cin >> c1) {
        if(c0 == ':' and c1 == '-') {
            while(c1 == '-' and cin >> c1)
            if(c1 == '(') ++sad;
            else if(c1 == ')') ++happy;

        } else if(c0 == '(' and c1 == '-') {
            while(c1 == '-' and cin >> c1)
            if(c1 == ':') ++happy;

        } else if(c0 == ')' and c1 == '-') {
            while(c1 == '-' and cin >> c1)
            if(c1 == ':') ++sad;
        }
        c0 = c1;
    }
    cout << happy << ' ' << sad << endl;
}