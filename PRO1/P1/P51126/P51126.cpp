/* Intervals (1) - 17/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d; // a,b and c,d will be the brackets that will be formed. a<b and c<d

    int min, max; // These are the values that will appear inside the brackets.

    

    if (c<=b and a<=d)
    {
        if (a<c)
        {
            min = c;
        } else
        {
            min = a;
        }

        if (b<d)
        {
            max = b;
        } else
        {
            max = d;
        }
        cout << "[" << min << "," << max << "]" << endl;
    } else
    {
        cout << "[]" << endl;
    }
    
    
    

}