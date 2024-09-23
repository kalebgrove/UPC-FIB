#include <iostream>

using namespace std;

int main() {
    int n;
    int pos = 0;
    bool found = false;

    while (not found) {
        cin >> n;
        if(n%2 == 0) found = true;
        ++pos;
    }
    cout << pos << endl;
}