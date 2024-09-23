#include "sumAtDepthEven.hh"

int sumAtDepthEven(BinTree<int> t) {
    //Base case
    if(t.empty()) return 0;

    //Recursive case
    int sum = t.value();
    if(not t.left().empty()) {
        sum += sumAtDepthEven(t.left().left()) + sumAtDepthEven(t.left().right());
    }
    if(not t.right().empty()) {
        sum += sumAtDepthEven(t.right().left()) + sumAtDepthEven(t.right().right());
    }

    return sum;
}