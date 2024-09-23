#include <iostream>

using namespace std;

void info_sequence(int& sum, int& last) {
    int n;
    while(cin >> n and n != 0) {
        sum += n;
        last = n;
    }
}
int main() {
    int sum = 0, last = 0;
    info_sequence(sum, last);

    const int fst_sum = sum, fst_last = last;
    int ctr = 1;

    int n;

    while(cin >> n and n != 0) {
        sum = n, last = n;
        info_sequence(sum, last);
        if(sum == fst_sum and last == fst_last) ++ctr;
    }
    cout << ctr << endl;
}