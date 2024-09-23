#include <iostream>

using namespace std;

void names(string s, int n, int ctr){
    bool even = false;
    if(cin >> s) {
        names(s, n, ++ctr);
        if(ctr%2 == 0) even = true;
        if(even) {
            if(ctr >= n) cout << s << endl;
        } else {
            if(ctr > n) cout << s << endl;
        }
    }

}

int main() {
    int n;
    cin >> n;
    string s = "";
    names(s, n, 0);
}