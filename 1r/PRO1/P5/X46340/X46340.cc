#include <iostream>

using namespace std;

int sum_min_max(int x, int y, int z) {
    int max = x;
    int min = x;
    if(y > max) max = y;
    else min = y;
    if(z > max) max = z;
    else if(z < min) min = z;

    return max+min;
}

int main() {
    cout << sum_min_max(23, 22, 20) << endl;
}