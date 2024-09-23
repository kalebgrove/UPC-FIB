/* Harmonic Numbers (1) - 24/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    cout.setf(ios::fixed);
    cout.precision(4);

    double Hn = 0;
    int i = 1;

    while (i <= n)
    {
        Hn += 1.0/i;
        ++i;
    }
    
    cout << Hn << endl;

}