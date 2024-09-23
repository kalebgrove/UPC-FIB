/* Control C202D - 24/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
using namespace std;

int main(){
    int a, b;
    int sum = 0;

    while(cin >> a >> b){
    int i = a;

    while(i <= b){
            sum += i*i*i;
            ++i;
    }
    cout << "suma dels cubs entre " << a << " i " << b << ": " << sum << endl;
    sum = 0;
    }
}