#include <iostream>

using namespace std;

int main() {
    const int peak = 3143;

    int n, val;
    bool found_zero = false;
    bool succ_peak = false;

    while(cin >> n and not found_zero and not succ_peak) {
        if(n <= peak) {
            while(cin >> n and not found_zero and not succ_peak) {
                if(n > peak and not found_zero) {
                    int val = n;
                    cin >> n;
                    if(n != 0 and val > n) succ_peak = true;
                    else succ_peak = false;
                }
            } 
        }
        if(n == 0) found_zero = true;
    }
    if(succ_peak) cout << "YES" << endl;
    else if(found_zero) cout << "NO" << endl;
}