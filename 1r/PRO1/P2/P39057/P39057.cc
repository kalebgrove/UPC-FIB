/* Computing Areas - 29/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){
    cout.setf(ios::fixed);
    cout.precision(6);

    int n;
    cin >> n;

    string shape = "";

    for (int i = 0; i < n; ++i)
    {
    cin >> shape;
        if(shape == "rectangle") {
            double height, width;
            cin >> height >> width;
            cout << height*width << endl;
        } else if (shape == "circle"){
            double radius;
            cin >> radius;
            cout << M_PI*radius*radius << endl;
        }
    }
}