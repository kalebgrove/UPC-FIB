#include <iostream>

using namespace std;

int main(){
    int n;
    int sum = 0;

    while (cin >> n)
    {
    int aux = n;
        while (n > 0)
        {
            sum += n%10;
            n /= 10;
        }
        cout << "The sum of the digits of " << aux << " is " << sum << '.' << endl;
        sum = 0;
    }
}