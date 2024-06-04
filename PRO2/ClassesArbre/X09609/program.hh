void sub_arrel_aux(Arbre& asub, node_arbre* n, const T& x, bool& found) {
    //Base case
    if(n == NULL) {
        return;
    }
    
    if(not found) {
        if(n->info == x) {
            found = true;
            asub.primer_node = copia_node_arbre(n);
            return;
        }
        else {
            sub_arrel_aux(asub, n->segE, x, found);
            if(not found) sub_arrel_aux(asub, n->segD, x, found);
            return;
        }
    }

    return;
}

void sub_arrel(Arbre& asub, const T& x) {
    bool found = false;
    sub_arrel_aux(asub, asub.primer_node, x, found);
}
 /* Pre: p.i. = A, asub es buit */
 /* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
    si A no conte x, asub es buit */