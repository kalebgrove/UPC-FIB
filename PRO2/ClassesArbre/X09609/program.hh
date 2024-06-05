void sub_arrel(Arbre& asub, const T& x){
    int a = 0;
    asub.primer_node = copia_node_arbre(aux(this->primer_node, x, a));
}
 /* Pre: p.i. = A, asub es buit */
 /* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
    si A no conte x, asub es buit */

node_arbre* aux(node_arbre* p, const T& x, int& c){
    if (p==nullptr)
    {
        return nullptr;
    }
    if (p->info == x)
    {
        return p;
    }
    

    c++;
    int c1 = c;
    int c2 = c;

    node_arbre* p1 = aux(p->segE, x, c1);
    node_arbre* p2 = aux(p->segD, x, c2);

    if (p1==nullptr and p2==nullptr)
    {
        return nullptr;
    }
    if (p1==nullptr or p2==nullptr)
    {
        if (p1==nullptr)
        {
            return p2;
        }
        
        return p1;
    }
    
    if (c1>c2)
    {
        return p2;
    }
    
    return p1;
    
    
}