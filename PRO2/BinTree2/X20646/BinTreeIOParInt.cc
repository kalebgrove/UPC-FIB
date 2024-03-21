#include "BinTreeIOParInt.hh"
#include "ParInt.hh"

void read_bintree_parint(BinTree<ParInt>& a) {
    ParInt par;
    //Base case
    if(not par.llegir()) {
        return; //Both numbers are 0.
    }

    //Recursive case
    BinTree<ParInt> left;
    BinTree<ParInt> right;

    read_bintree_parint(left);
    read_bintree_parint(right);

    a = BinTree<ParInt>(par, left, right);
}