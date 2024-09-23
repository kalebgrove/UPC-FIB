#include <iostream>

using namespace std;

bool is_perfect(int n) {
    int sum = 0;
    for(int i = 1; i < n; ++i) {
        if(n%i == 0) sum += i;
    }
    if(n == 1 or n == 0) return false;
    else if(sum == n) return true;
    return false;
}

int main() {
    if(is_perfect(28)) cout << "true" << endl;
    else cout << "false" << endl;
}