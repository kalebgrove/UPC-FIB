/* Uppercase and lowercase letters - 12/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
using namespace std;

int main(){
    char letter;
    cin >> letter;
    if((int(letter) <= 122) && (int(letter) >= 97)){
        cout << char(letter - 'a' + 'A') << endl;
    } else {
        cout << char(letter - 'A' + 'a') << endl;
    }
}