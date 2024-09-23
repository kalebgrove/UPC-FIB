#include <iostream>

using namespace std;

int main() {
    int n, pair1, pair2;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        int count = 0;

        cin >> pair1;
        while(pair1 != 0) {
            cin >> pair2;
            if(pair1 < pair2) ++count;
            pair1 = pair2;
        }
        cout << count << endl;
    }
    
}