#include <iostream>

using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(2);

    double n;
    string s;

    cin >> n;
    cin >> s;

    if(s == "euros") {
        n *= 1.254;
        cout << n << " dolars" << endl;
    } else {
        n /= 1.254;
        cout << n << " euros" << endl;
    }
}