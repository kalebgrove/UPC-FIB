/* Modificació d'un BinTree de parells

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "BinTree.hh"
#include "ParInt.hh"


/*Pre: a = A */
/*Post: a es com a A amb k sumat al segon component de cada node */
void sumak(BinTree<ParInt>& a, int k) {
    //Base case
    if(a.empty()) return;

    //General case
    int num = a.value().segon();
    num += k;

    BinTree<ParInt> aux1 = a.left();
    BinTree<ParInt> aux2 = a.right();

    sumak(aux1, k);
    sumak(aux2, k);

    auto aux = BinTree<ParInt> (ParInt(a.value().primer(), a.value().segon() + k), aux1, aux2);

    a = aux;
}