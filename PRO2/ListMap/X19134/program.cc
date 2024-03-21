/* Cerca en una llista de parells d'enters

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "LlistaIOParInt.hh"
#include "ParInt.hh"

using namespace std;

int main() {
    list<ParInt> l;

    LlegirLlistaParInt(l);

    int num;
    cin >> num;

    int tot = 0;
    int sum = 0; //Total sum of num.

    for(list<ParInt>::iterator it = l.begin(); it != l.end(); ++it) {
        ParInt p = *it;
        if(p.primer() == num) {
            ++tot;
            sum += p.segon();
        }
    }
    cout << num << ' ' << tot << ' ' << sum << endl;
}