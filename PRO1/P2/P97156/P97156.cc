#include <iostream>
#include <string>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    string null;

    if (a <= b)
    {
        cout << a;
        for (int i = a + 1; i <= b; i++)
        {
            cout << "," << i;
        }
        
    }

    cout << endl;
    
}