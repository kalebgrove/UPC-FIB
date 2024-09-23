/* Multiplication Table - 24/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

/*    for (int i = 1; i < 11; i++)
    {
        cout << n << "*" << i << " = " << n*i << "\n";
    }
*/
    int i = 1;

    while (i <= 10)
    {
        cout << n << "*" << i << " = " << n*i << "\n";
        ++i;
    }
    
    
}