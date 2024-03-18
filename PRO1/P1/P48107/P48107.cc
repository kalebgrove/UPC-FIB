/* Integer division and remainder of two natural numbers - 08/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int var1, var2;
    cin >> var1 >> var2;
   // int divisor = var1/var2;
    // int residu = var1 - divisor*var2;
    cout << var1/var2 << " " << var1 - (var1/var2)*var2 << endl;
}