#include <iostream>
using namespace std;

void factor(int n, int& f, int& q){
    int tempq = 0;
    q = tempq;

    for(int i = 2; i*i <= n; ++i) {
        while(n % i == 0) {
                ++tempq;
                n /= i;
        }
        if(q < tempq) {
            f = i;
            q = tempq;
        }
        tempq = 0;
    }
    if(q == 0) {
        f = n;
        q = 1;
    }
}

int main() {
  int n;
  while (cin >> n) {
    int f = -1, q = 1000;
    factor(n, f, q);
    cout << f << ' ' << q << endl;
  }
}
