#include "searchInBST.hh"

bool searchInBST(BinTree<int> t, int x) {
    //Base case
    if(t.empty()) return false;
    if(t.value() == x) return true;

    //General case
    if(x < t.value()) return searchInBST(t.left(), x);
    if(x > t.value()) return searchInBST(t.right(), x);

    return false;

}