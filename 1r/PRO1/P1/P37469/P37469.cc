/* Time Decomposition (1) - 09/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    int hours = n/3600;
    int min = (n%3600)/60;
    int sec = (n%3600)%60;
    cout << hours << " " << min << " " << sec << endl;
}