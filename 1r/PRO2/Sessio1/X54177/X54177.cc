/* Suma de secuencias de enteros

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>

using namespace std;

int main() {
    int n, x;

    cin >> n >> x;

    for(int i = 0; i < n; ++i) {
        int m;
        int sum = 0;
        while(cin >> m and m != x) {
            sum += m;
        }
        cout << "La suma de la secuencia " << i+1 << " es " << sum << endl;
        string s;
        getline(cin, s);
    }
}