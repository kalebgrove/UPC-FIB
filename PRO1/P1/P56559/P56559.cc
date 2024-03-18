/* Intervals (2) - 17/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d; // intervals are a,b and c,d. If [a,b] = [c,d] then "=", if [a,b] is inside [c,d] then "1", if [c,d] is inside [a,b] then "2" and lastly, then print "?"
    string value; //Value that will print

    if ((c<a and b<=d) or (c<=a and b<d))
    {
        value = "1";
    } else if (c==a and d==b)
    {
        value = "=";
    } else if ((a<=c and d<b) or (a<c and d<=b))
    {
        value = "2";
    } else
    {
        value = "?";
    }
    
    cout << value << endl;    

}