/* Leap Years - 13/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
using namespace std;

int main(){
    int year;
    cin >> year;
    if(((year%100==0)&&((year/100)%4==0)) || ((year%100 != 0)&&(year%4 == 0))){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    /*
    if(year%100 == 0){
        if(((year/100)%4 == 0)){
        cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else if(year%100 != 0){
        if(year%4 == 0){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        
    }*/
}