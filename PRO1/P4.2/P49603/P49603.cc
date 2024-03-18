#include <iostream>

using namespace std;

int main() {
    int n;
    bool larger = false;
    int count = 0, max = 0;

    while(cin >> n) {
        string s;
        string prev_s = "A";

        larger = true;

        for(int i = 0; i < n; ++i) {
            cin >> s;
            if(prev_s > s) larger = false;
            prev_s = s;
        }
        ++count;
        if(larger) max = count;
    }
    if(max != 0) cout << "The last line in increasing order is " << max << ".\n";
    else cout << "There is no line in increasing order.\n";
}