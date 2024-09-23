#include <iostream>
#include <string>

using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    double c, i;
    int t; // initial capital, interest rate and time in years.
    string type; // Type of interest.
    cin >> c >> i >> t >> type;

    double balance = c; // Balance after interest.

    if (type == "simple") {
        for (int x = 0; x < t; ++x) {
            balance = balance + c*(i/100.0);
        }     
    } else {
        for (int y = 0; y < t; ++y) {
            balance = balance + balance*(i/100);
        }
    }
    cout << balance << endl;
}