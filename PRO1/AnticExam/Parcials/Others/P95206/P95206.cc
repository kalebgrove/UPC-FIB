#include <iostream>

using namespace std;

int main() {
    int n, n1;
    int count = 0;
    int sum = 0;

    while(cin >> n >> n1){
        count = 0;
        sum = 0;
        while(n > 0 or n1 > 0) {
            if(n%10 != n1%10){
                ++count;
                sum += n%10 + n1%10;
            }
            n /= 10;
            n1 /= 10;
        }
        cout << count << ' ' << sum << endl;
    }
}