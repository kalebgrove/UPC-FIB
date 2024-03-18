/* Add one second - 16/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int hour, min, sec;
    cin >> hour >> min >> sec;

    int sum = hour*3600 + min*60 + sec + 1;
    int final_h = sum/3600;
    int final_m = sum%3600/60;
    int final_s = sum%3600%60;
    string h, m, s;

    if (final_h < 10) h = "0";
    if (final_m < 10) m = "0";
    if (final_s < 10) s = "0";
    if (final_h == 24) final_h = 0, h = "0";

    cout << h << final_h << ":" << m << final_m << ":" << s << final_s << endl;
}