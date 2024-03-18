/* How many seconds are they? - 09/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int year, day, hour, min, sec;
    cin >> year >> day >> hour >> min >> sec;
    cout << year*365*24*3600+day*24*3600+hour*3600+min*60+sec << endl;
}