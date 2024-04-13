#include <iostream>

using namespace std;

int main() {
    int n, n1; // These are the numbers from the input.
    cin >> n >> n1;
    int derivative, derivative1;

    derivative = n1 - n;
    n = n1;

    bool positive_s = derivative > 0;
    bool positive_ss = true;
    bool end = false;

    while(cin >> n1 and not end) {
        derivative1 = n1 - n;
        if(derivative1 <= 0) positive_s = false;
        positive_ss = derivative1 - derivative > 0;
        n = n1;
        derivative = derivative1;
        if(not positive_s and not positive_ss) end = true;
    }
    
    if(positive_s or positive_ss) cout << "solvent economy\n";
    else cout << "not solvent economy\n";
}