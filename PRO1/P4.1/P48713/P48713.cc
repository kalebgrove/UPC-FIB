#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int x;
    int result;

    for(int i = 0; i < n; ++i) {
        cin >> x;
        bool res = false;
        if(x == 1 or x == 0) res = true;
        int j = 2;
        while(not res and j <= sqrt(x)){
            result = x%j;
            if(result == 0 and j != 1 and j != x) res = true;
            ++j;
        }
        if(res) cout << x << " is not prime" << endl;
        else cout << x << " is prime" << endl;
        }
    }