/* Avaluar expressions sense variables

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "evaluate.hh"
#include "utils.hh"

int evaluate(BinTree<string> t) {
    //Base case
    if(t.empty()) return 0;

    if(isNumber(t.value())) {
        return mystoi(t.value());
    }

    //General case

    if(t.value() == "+") {
        return evaluate(t.left()) + evaluate(t.right());
    } else if(t.value() == "-") {
        return evaluate(t.left()) - evaluate(t.right());
    } else {
        return evaluate(t.left()) * evaluate(t.right());
    }

}