#include "maximumTree.hh"


//We shall store the resulting graph into the a1 tree.
BinTree<int> maximumTree(BinTree<int> a1, BinTree<int> a2) {
    //Base case
    if(a1.empty() and a2.empty()) return a1;
    if(a2.empty()) return a1;
    if(a1.empty()) return a2;

    //General case
    
    if(a1.value() >= a2.value()) {
        return BinTree<int> (a1.value(), maximumTree(a1.left(), a2.left()), maximumTree(a1.right(), a2.right()));

    } 
    return BinTree<int> (a2.value(), maximumTree(a1.left(), a2.left()), maximumTree(a1.right(), a2.right()));
}