#include <iostream>

using namespace std;

//Pre: given n, odd, and c, a character.
//Post: we print a cross such that the middle row contains n characters that have been selected in the argument.

void cross(int n, char c) {
    int middle = (n - 1)/2;
    for(int i = 0; i < n; ++i) {
        if(i == middle) {
            for(int j = 0; j < n; ++j) {
                cout << c;
            }
            cout << endl;
        } else {
            for(int j = 0; j < middle; ++j) {
                cout << ' ';
            }
            cout << c << endl;
        }
    }
}

int main() {
    cross(9, 'a');
}