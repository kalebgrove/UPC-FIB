/* Fusió ordenada des d'una altra llista

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "mergeIntoFirstList.hh"

// Pre: l1 i l2 estan ordenades creixentment. Siguin L1 i L2 els seus valors inicials.
// Post: l1 conté la fusió ordenada de L1 i L2.
//       A més a més, els elements inicials de la llista han persistit i
//       no han canviat de valor.
void mergeIntoFirstList(list<int> &l1, list<int> l2) {
    list<int>::iterator i = l1.begin();
    while(not l2.empty()) {
        if(i == l1.end() or *i > l2.front()) {
            l1.insert(i, l2.front());
            l2.pop_front();
        } else {
            i++;
        }
    }
}