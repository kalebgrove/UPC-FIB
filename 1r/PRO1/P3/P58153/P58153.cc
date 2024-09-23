#include <iostream>

using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(10);

    int n, m;

    while (cin >> n >> m)
    {
    double harm_n = 0;
    double harm_m = 0;
        for (double i = 1; i <= n; ++i)
        {
            harm_n += 1/i;
        }
        for (double j = 1; j <= m; ++j)
        {
            harm_m += 1/j;
        }
        cout << harm_n - harm_m << endl;
    }
}