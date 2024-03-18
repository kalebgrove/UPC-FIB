#include <iostream>

using namespace std;

void bars(int n) {
    if(n == 0) return;

    bars(n-1);
    // void bars(int n-1) {                 n = 4;
    //  if(3 == 0 (not)) return;
    //  bars(n-1)
    //      void bars(int n-2) {
    //          if(2 == 0) return;
    //          bars(n-3);
    //              void bars(n-3) {
    //                  if(1 == 0) return;
    //                  bars(n-4);
    //                      void bars(int n-4) {
    //                          if(0 == 0) return;
    //                      }
    //              }
    //      }
    //  }
    for(int i = 0; i < n; ++i) cout << '*';
    cout << endl;
    bars(n-1);
}

int main() {
    int n;
    cin >> n;
    bars(n);
}