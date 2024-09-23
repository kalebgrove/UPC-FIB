#include <iostream>

using namespace std;

int main(){
    int d, n, t;
    cin >> d >> n >> t; // d is fixed weekly expenses, which means that every week that there is, defined by t, is how much the
                        // person will need to pay. n is the money saved up previously. t also defines the amount of times you get
                        // an arbitrary allowance.
    int allowance;
    int cnt = 0;        // This is the counter for how many weeks we have a positive difference.

    for (int i = 0; i < t; ++i)
    {
        cin >> allowance;
        n = n + allowance - d;
        if(n > 0) {
            ++cnt;
        }
    }
    cout << cnt << endl;
}