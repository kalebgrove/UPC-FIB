#include <iostream>

using namespace std;

int main() {
    int n; //Numbers that will be read.

    while(cin >> n) {
        int t_amount = 0;
        int temp_ctr = 0, ctr = 0, sum = n;

        while(n != -1) {
            ++t_amount;
            if(n <= sum) ++temp_ctr;
            else temp_ctr = 0;

            sum += n;

            ctr = max(ctr, temp_ctr);
            cin >> n;
        }

        if(t_amount != 0) cout << ctr << endl;
        else cout << 0 << endl;
    }
}