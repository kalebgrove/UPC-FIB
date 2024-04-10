/* Avaluar expressions amb strings

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "evaluate.hh"

string rev(string& s) {
    int n = s.size() - 1;
    string s2 = "";
    for(int i = n; i >= 0; --i) {
        s2 += s[i];
    }
    return s2;
}

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre strings de lletres minúscules i els operadors Concat, Reverse.
// Post: Retorna l'avaluació de l'expressió representada per t.
string evaluate(BinTree<string> t) {
    //Base case
    if(t.empty()) return "";

    //Recursive case
    string tleft = evaluate(t.left());
    string tright = evaluate(t.right());

    if(t.value() == "Concat") return tleft + tright;
    else if(t.value() == "Reverse") return rev(tleft);

    return t.value();
}