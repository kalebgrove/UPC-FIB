#include <iostream>
#include <cmath>

using namespace std;

//Pre: we will be given a prime number.
//Post: the consecutive prime number will be printed.

bool prime1(int n) {
    if(n <= 1) return false;
    for(int i = 2; i <= sqrt(n); ++i) {
        if(n%i == 0) return false;
    }
    return true;
}

int prime2(int n) {
    int next = n+1;
    while(true) {
        if(prime1(next)) return next;
        ++next;
    }
}

int main() {
    int n;
    while(cin >> n) {
        if(prime1(n)) {
            cout << prime2(n) << endl;
        } else {
            break;
        }
    }
}