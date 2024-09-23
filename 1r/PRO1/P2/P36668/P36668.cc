/* Sum of squares - 24/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int sum = 0;
    int i = 1;

    while (i <= n)
    {
        sum += i*i;
        ++i;
    }
       
    cout << sum << endl;    

}