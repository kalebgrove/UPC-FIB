#include <iostream>

using namespace std;

int main() {
    int x;

    while (cin >> x) {
        int pow10_e = 1;
        int pow10_o = 1;
        int even = 0;
        int odd = 0;

        while (x > 0) {
            if (x%2 == 0 and x%10 != 0) {
                even = (x%10)*pow10_e + even;
                pow10_e *= 10;
            } else if (x%2 == 1){
                odd = (x%10)*pow10_o + odd;
                pow10_o *= 10;
            }
            x /= 10;
        }
        odd *= pow10_e;
        cout << odd + even << ' ' << 2*(odd+even) << endl;
    }
}