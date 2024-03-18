/* Control C101A - 21/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int var1;
    cin >> var1;
    int unit = var1%10;
    int dec = (var1/10)%10;
    int hund = (var1/100)%10;
    cout << unit+dec+hund << endl;

}