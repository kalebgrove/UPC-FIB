T max_suma_aux(node_arbre* n) const {
    //We have to travel the tree in postorder because we don't know what subtrees are empty and which aren't
    //Base case
    if(n == NULL) return 0;
    
    else if(n->segE == NULL and n->segD == NULL) return n->info;

    //Recursive case
    T esq = n->info + max_suma_aux(n->segE);
    T dre = n->info + max_suma_aux(n->segD);

    if(esq >= dre) {
        return esq;
    }
    return dre;
    
}

T max_suma_cami() const {
    return max_suma_aux(primer_node);
}
/* Pre: el parametre implicit no es buit */
/* Post: el resultat es la suma del cami de suma maxima del parametre implicit */