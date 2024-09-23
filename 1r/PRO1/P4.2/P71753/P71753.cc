#include <iostream>

using namespace std;

int main() {
    int n, seq;
    while(cin >> n) {
        cin >> seq;
        int max = seq;
        for(int i = 0; i < n - 1; ++i) {
            cin >> seq;
            if(seq > max) max = seq;
        }
        cout << max << endl;
    }
}