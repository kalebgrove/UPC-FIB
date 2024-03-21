#include "reverseTree.hh"

BinTree<int> reverseTree(BinTree<int> t) {
    //Base case
    if(t.empty()) return t;

    //General case

    t = BinTree<int>(t.value(), reverseTree(t.right()), reverseTree(t.left()));

    return t;
}