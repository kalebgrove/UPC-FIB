/* Avaluar expressions booleanes

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "evaluate.hh"

// Pre:  t és un arbre no buit que representa una expressió booleana correcta
//       sobre els valors true,false i els operadors and,or,not.
// Post: Retorna l'avaluació de l'expressió representada per t.
bool evaluate(BinTree<string> t) {
    //Base case
    if(t.empty()) return false;
    if(t.value() == "false") return false;
    if(t.value() == "true") return true;

    //Recursive case

    if(t.value() == "and") {
        return evaluate(t.left()) and evaluate(t.right());
    } else if(t.value() == "or") {
        return evaluate(t.left()) or evaluate(t.right());
    } else {
        if(not t.left().empty()) {
            if(evaluate(t.left())) return false;
            return true;
        }
        if(evaluate(t.right())) return false;
        return true;
    }
}