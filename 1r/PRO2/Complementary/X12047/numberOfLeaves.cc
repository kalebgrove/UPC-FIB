/* Nombre de fulles d'un arbre

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>
#include "BinTree.hh"
#include "numberOfLeaves.hh"

using namespace std;

// Pre: true
// Post: Retorna el nombre de fulles de t
int numberOfLeaves(BinTree<int> t) {
    //Base case
    if(t.empty()) return 0;
    else if(t.right().empty() and t.left().empty()) return 1;

    //Recursive case
    return numberOfLeaves(t.left()) + numberOfLeaves(t.right());
}