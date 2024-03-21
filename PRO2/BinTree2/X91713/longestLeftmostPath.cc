#include "longestLeftmostPath.hh"
#include <cmath>

BinTree<int> treeOfHeights(BinTree<int> t) {
    //Base case
    if(t.empty()) return BinTree<int> (0);  //Since we do pathing of preorder, we will reach both ends before accessing the node, and we assign it a value of 0.
                                            //Therefore, the node above them will be 1+max(0,0), which is 1, and so on until reaching the top.

    //Recursive case
    BinTree<int> tree_left = treeOfHeights(t.left());
    BinTree<int> tree_right = treeOfHeights(t.right());

    int height_left = tree_left.value();
    int height_right = tree_right.value();

    return BinTree<int> (1+max(height_left, height_right), tree_left, tree_right);
}

list<int> longestPathAux(BinTree<int> t, BinTree<int> treeheight) {
    //Base case
    if(treeheight.value() == 0) {
        return list<int> ();
    }

    //Recursive case
    if(treeheight.left().value() < treeheight.right().value()) {
        list<int> l = longestPathAux(t.right(), treeheight.right());
        l.push_front(t.value());
        return l;
    } else {
        list<int> l = longestPathAux(t.left(), treeheight.left());
        l.push_front(t.value());
        return l;
    }
}

list<int> longestLeftmostPath(BinTree<int> t) {

    BinTree<int> treeheight = treeOfHeights(t);
    return longestPathAux(t, treeheight);
}
    