#include "evaluate.hh"
#include "utils.hh"

int evaluate(map<string, int>& variable2value, BinTree<string> t) {
    //Base case
    if(t.empty()) return 0;

    //Recursive case

    if(isNumber(t.value())) return mystoi(t.value());
    if(isVariable(t.value())) return variable2value[t.value()];

    if(t.value() == "+") return evaluate(variable2value, t.left()) + evaluate(variable2value, t.right());
    if(t.value() == "*") return evaluate(variable2value, t.left()) * evaluate(variable2value, t.right());
    if(t.value() == "-") return evaluate(variable2value, t.left()) - evaluate(variable2value, t.right());

    return -1; //Si no se cumpla el PRE.
}