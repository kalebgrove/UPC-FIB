#include <iostream>

using namespace std;

int main() {
    char c1, c2, c3;
    int happy = 0, sad = 0;
    cin >> c1 >> c2;
    
    while(cin >> c3) {

        if(c1 == '(' and c2 == '-' and c3 == ':') ++happy;
        else if(c1 == ')' and c2 == '-' and c3 == ':') ++sad;
        else if(c1 == ':' and c2 == '-' and c3 == ')') ++happy;
        else if(c1 == ':' and c2 == '-' and c3 == '(') ++sad;
        c1 = c2;
        c2 = c3;
    }
    cout << happy << ' ' << sad << endl;
}