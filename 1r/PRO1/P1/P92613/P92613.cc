/* Rounding - 18/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double number;
    cin >> number;

    int ceiling;
    double decimal = number-int(number);

    if (decimal > 0)
    {
        ceiling = number + 1;
    } else
    {
        ceiling = number;
    }
    
    int rou = number+0.5;
    cout << int(number) << " " << ceiling << " " << rou << endl;
}