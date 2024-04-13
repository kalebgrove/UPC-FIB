#include <iostream>

using namespace std;

int main(){
    string s, s1, s2;
    cin >> s >> s1 >> s2;
    string min = s;
    if(min > s1) min = s1;
    if(min > s2) min = s2;
    cout << min << endl;
}