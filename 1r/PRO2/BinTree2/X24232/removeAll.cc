/* Esborra fitxers amb una extensió

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "removeAll.hh"

string ext(string& s) {
    int n = s.size();
    string s2 = "";
    int i = 0;
    while(s[i] != '.' and i < n) {
        ++i;
    }
    if(s[i] == '.') {
        ++i;
        
        while(i < n) {
            s2 += s[i];
            ++i;
        }
    } 
    return s2;
}

// Pre:  Els nodes de 't' o bé son strings no buits de lletres minuscules, o bé
//       son de la forma "s.e", on s i e son strings no buits de lletres minúscules.
//       En l'últim cas, el node ha de ser una fulla, i e s'anomena la extensió de la fulla.
// Post: Retorna l'arbre resultant d'esborrar de t tots els nodes amb strings de
//       la forma "s.e" a on 'e' és igual a 'extension'.
BinTree<string> removeAll(const string &extension, const BinTree<string> &t) {
    //Base case
    if(t.empty()) return BinTree<string> ();

    //Recursive case
    string image = t.value();
    if(ext(image) == extension) return BinTree<string> ();
    else return BinTree<string> (t.value(), removeAll(extension, t.left()), removeAll(extension, t.right()));
}