#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double x;
    
    double sum = 0;
    int i = 0; // This is the denominator that will divide the sum.
    
      // Set the precision of the next values.

    while(cin >> x){
        cout.setf(ios::fixed);
        cout.precision(2);
        sum += x;
        ++i;
    }

    double average = sum/i;

    cout << average << endl;

}