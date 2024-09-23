/* Arbre d'avaluacions d'expressió booleana

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "treeOfEvaluations.hh"

// Pre:  t és un arbre no buit que representa una expressió booleana correcta
//       sobre els valors true,false i els operadors and,or,not.
// Post: Retorna un arbre binari de booleans
//       que té el mateix conjunt de posicions que t.
//       A més a més, per a cada posició p, el subarbre a posició p de t
//       representa una expressió que s'avalua a true si i només si
//       hi ha el valor true a la posició p de l'arbre retornat.

BinTree<bool> treeOfEvaluations(BinTree<string> t) {
    //Base case
    if(t.empty()) return BinTree<bool> ();
    if(t.value() == "true") return BinTree<bool> (true);
    if(t.value() == "false") return BinTree<bool> (false);

    //Recursive case

    auto tleft = treeOfEvaluations(t.left());
    auto tright = treeOfEvaluations(t.right());

    if(t.value() == "and") {
        return BinTree<bool>(tleft.value() and tright.value(), tleft, tright);

    } else if(t.value() == "or") {
        return BinTree<bool>(tleft.value() or tright.value(), tleft, tright);

    } else if(t.value() == "not") {
        return BinTree<bool>(!tleft.value(), tleft, BinTree<bool> ());
        
    }

    return BinTree<bool> ();
}