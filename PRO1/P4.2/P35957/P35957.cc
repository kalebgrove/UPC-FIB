#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int prev_middle = -1;
    int i = 0;

    char result = '=';

    while(result == '=' and i < 2*n) {
        int dig;
        cin >> dig;

        int num_dig = 1;
        int x = dig;
        while(x >= 10) {
            x /= 10;
            ++num_dig;
        }

        bool even = false;
        int middle;
        if(num_dig%2 == 0) even = true;
        else {
            num_dig = (num_dig - 1)/2;
            while(num_dig > 0) {
                dig /= 10;
                --num_dig;
            }
            middle = dig%10;
        }

        if(even or (i > 0 and prev_middle != middle)) {
            if(i%2 == 0) result = 'B';
            else result = 'A';
        }

        prev_middle = middle;
        ++i;
    }
    cout << result << endl;
}