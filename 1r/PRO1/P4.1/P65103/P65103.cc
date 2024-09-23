#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int x;
    int pos = 1;
    bool found = false;

    while(cin >> x) {
        if(pos == n) {
            cout << "At the position " << n << " there is a(n) " << x << '.' << endl;
            found = true;
        }
        ++pos;
    }

    if(not found) cout << "Incorrect position." << endl;
}