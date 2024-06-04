int freq_aux(node_arbre* n, const T& x) const {
    //Base case
    if(n == NULL) return 0;

    //Recursive case
    int sum = 0;

    if(n->info == x) {
        ++sum;
    }

    return sum + freq_aux(n->segE, x) + freq_aux(n->segD, x);
}

int freq(const T& x) const {
    return freq_aux(primer_node, x);
}
/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */