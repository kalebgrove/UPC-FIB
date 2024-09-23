/* Maximum of three integer numbers - 12/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
   /*int a, b, c;
    cin >> a >> b >> c;
    if ((a>=b) && (a>=c)){
        cout << a << endl;
    } else if ((b>=c) && (b>=a)){
        cout << b << endl;
    } else {
        cout << c << endl;
    }*/

    int a, b, c, maximum;
    cin >> a >> b >> c;
    maximum = max(a,b);
    maximum = max(maximum, c);
    cout << maximum << endl;

}