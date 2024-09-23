#include <iostream>

using namespace std;

int main() {
    char c;
    cin >> c;

    while(c != '.' and c != 'a') cin >> c;
    
    if(c == 'a') cout << "yes" << endl;
    else cout << "no" << endl;
}