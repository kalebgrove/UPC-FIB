/* Cerca en un BinTree de parells d'enters

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "ParInt.hh"
#include "BinTree.hh"
#include "BinTreeIOParInt.hh"

ParInt level(BinTree<ParInt> a, int depth, int first) {
    //Base case
    if(a.empty()) return ParInt(-1, 0);
    if(a.value().primer() == first) return ParInt(a.value().segon(), depth);

    //Recursive case

    ParInt left = level(a.left(), depth+1, first);
    ParInt right = level(a.right(), depth+1, first);

    if(left.primer() != -1) return left;
    if(right.primer() != -1) return right;

    return ParInt(-1, 0);
}

int main() {
    BinTree<ParInt> a;
    read_bintree_parint(a);

    int x;
    while(cin >> x) {
        int depth = 0;
        ParInt second = level(a, depth, x);

        if(second.primer() == -1) cout << -1 << endl;
        else cout << x << ' ' << second.primer() << ' ' << second.segon() << endl;
    }
}