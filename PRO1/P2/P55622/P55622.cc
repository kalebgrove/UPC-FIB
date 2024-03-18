/* Number of digits (1) - 24/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int dig = 1;
    int i = n;
    
    while (i > 9)
    {
        i /= 10;
        ++dig;
    }
    
    cout << "The number of digits of " << n << " is " << dig << "." << endl;
    cout << "kaleb es gilipichis\n";

}