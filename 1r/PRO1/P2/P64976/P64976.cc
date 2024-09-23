#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string null;

    int i = 1;

    if (n != 0)
    {
        while (i <= n)
        {
            cout << n << " x " << i << " = " << n*i << "\n";
            ++i;
        }
        
    } else
    {
        cout << null;
    }
    
}