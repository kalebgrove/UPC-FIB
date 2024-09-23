#include "sumOfTree.hh"

int sumOfTree(BinTree<int> t) {
    if(t.empty()) return 0;

    int sum = t.value();
    sum += sumOfTree(t.left());
    sum += sumOfTree(t.right());

    return sum;
}