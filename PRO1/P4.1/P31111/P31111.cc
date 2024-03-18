#include <iostream>

using namespace std;

int main() {
    char parenthesis;
    int open = 0, close = 0;
    bool more_close = false;

    while(not more_close and cin >> parenthesis) {
        if(parenthesis == '(') ++open;
        else ++close;
        if(open < close) more_close = true;
    }
    if(more_close or open != close) cout << "no" << endl;
    else cout << "yes" << endl;
}