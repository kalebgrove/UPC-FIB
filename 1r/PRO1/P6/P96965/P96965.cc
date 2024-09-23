#include <iostream>

using namespace std;

int sum_of_digits(int x) {
    if(x < 10) return x;
    return sum_of_digits(x/10) + x%10;
}

int reduction_of_digits(int x) {
    int sum = sum_of_digits(x);
    if(sum < 10) return sum;
    return reduction_of_digits(sum);
}


int main() {
    int n;
    while(cin >> n) cout << reduction_of_digits(n) << endl;
}