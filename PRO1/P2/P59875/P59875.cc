/* Top to bottom - 24/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;

    if (y >= x) {
        
        while (y >= x)
    {
        cout << y << endl;
        --y;
    }
    } else
    {
        while (x >= y)
        {
            cout << x << endl;
            --x;
        }
        
    }
    
}