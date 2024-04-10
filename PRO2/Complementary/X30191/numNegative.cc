/* Nombre d'expressions amb avaluació negativa

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "numNegative.hh"
#include "utils.hh"

int aux(BinTree<string> t, int& n) {
    //Base case
    if(t.empty()) return 0;

    //Recursive case
    if(isNumber(t.value())) return mystoi(t.value());

    int tleft = aux(t.left(), n);
    int tright = aux(t.right(), n);
    int total = 0;

    //cout << "left " << tleft << endl;
    //cout << "right " << tright << endl;

    if(t.value() == "+") {
        total = tleft + tright;
        if(total < 0) {
            ++n;
        }
    }
    else if(t.value() == "*") {
        total = tleft * tright;
        if(total < 0) {
            ++n;
        }
    }
    else {
        total = tleft - tright;
        if(total < 0) {
            ++n;
        }
    }
    //cout << "total " << total << endl;
    //cout << "n " << n << endl;
    return total;
}

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre els naturals i els operadors +,-,*.
//       Les operacions no produeixen errors d'overflow.
// Post: Retorna el nombre de subexpressions de l'expressió representada per t
//       amb avaluació estrictament menor que 0.
int numNegative(BinTree<string> t) {
    int n = 0;
    aux(t, n);
    return n;
}