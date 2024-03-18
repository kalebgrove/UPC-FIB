#include <iostream>

using namespace std;

int main() {
    int i;
    cin >> i;
    int x;
    for(int j = 0; j < i; ++j) {
        cin >> x;
    }
    cout << "At the position " << i << " there is a(n) " << x << '.' << endl;
}