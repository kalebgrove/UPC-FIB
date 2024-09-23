/* Control C102A - 19/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    int x, a, b, c, d;
    cin >> x >> a >> b >> c >> d; // We read the five values that have been previously declared. Now we need to see if x belongs to [a,b] or [c,d].

    string output; // What will we print?

    if (((x <= b) and (x >= a)) or ((x <= d) and (x >= c)))
    {
        output = "yes";
    } else
    {
        output = "no";
    }
    
    cout << output << endl;

}