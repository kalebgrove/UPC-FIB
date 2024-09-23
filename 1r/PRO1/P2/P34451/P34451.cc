/* Control C201C - 24/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
using namespace std;

int main(){
    int x;
    cin >> x;
    int y;
    int multiple = 0;

    while(cin >> y) {
        if (y%x == 0)
        {
            ++multiple;
        }
        
    }

    cout << multiple << endl;

}