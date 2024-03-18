#include <iostream>
#include <cmath>

using namespace std;


bool is_prime(int n) {
     if(n <= 1) return false;
    for(int i = 2; i <= sqrt(n); ++i) {
        if(n%i == 0) return false;
    }
    return true;
}

int calc(int n, int sum) {
    while(n > 0) {
        int rem = n%10;
        sum += rem;
        n /= 10;
    }
    return sum;
    calc(sum, 0);
}

bool is_perfect_prime(int n) {
    if(n >= 10) {
        if(is_prime(n)) {
            return is_perfect_prime(calc(n, 0));
        }
        return false;
    } else {
        if(is_prime(n)) return true;
        return false;
    }
}