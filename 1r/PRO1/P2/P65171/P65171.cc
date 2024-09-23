#include <iostream>

using namespace std;

int main(){
    cout.setf(ios::fixed);
    cout.precision(2);
    
    int n;
    cin >> n;

    double sum1 = 0;
    double sum2 = 0;

    double division1 = 1.0/(n - 1); // This is the division that will multiply the first sum.
    double division2 = 1.0/(n*(n-1)); // This is the division that multiplies the second sum.
    
    double x;

    for(int i = 0; i < n; ++i) {
        cin >> x;
        sum1 += x*x;
        sum2 += x;
    }
    cout << division1*sum1 - division2*sum2*sum2 << endl;
}