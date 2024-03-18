/* Elementos - 18/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    string el1, el2; //Dos elementos a introducir
    cin >> el1 >> el2;
    string result;

    if ((el1 == "A" and el2 == "P") or (el1 == "V" and el2 == "A") or (el1 == "P" and el2 == "V")) result = "1";
    if ((el1 == "P" and el2 == "A") or (el1 == "A" and el2 == "V") or (el1 == "V" and el2 == "P")) result = "2";
    if (el1 == el2) result = "-";
    
    cout << result << endl;

}