#include "Barco.hh"

Barco::Barco() {
    producto_a_comprar = -1;
    producto_a_vender = -1;

    unidades_a_comprar = -1;
    unidades_a_vender = -1;

    ciudad_anterior = "";
}

Barco::Barco(int producto_a_comprar, int producto_a_vender, double unidades_a_comprar, double unidades_a_vender) {
    this->producto_a_comprar = producto_a_comprar;
    this->producto_a_vender = producto_a_vender;

    this->unidades_a_comprar = unidades_a_comprar;
    this->unidades_a_vender = unidades_a_vender;

    ciudad_anterior = "";
}

void Barco::escribir_barco() const {
    cout << producto_a_vender << ' ' << unidades_a_vender << endl;
    cout << producto_a_comprar << ' ' << unidades_a_comprar << endl;

    int n = ultima_ciudad_viaje.size();

    for(int i = 0; i < n; ++i) {
        cout << ultima_ciudad_viaje[i] << endl;
    }
}

void Barco::hacer_viaje(BinTree<string>& mapa_rio, map<string, Ciudad>& lista_ciudades) {
    BinTree<pair<int, int> > weighted_tree = weighted_tree_rec(mapa_rio, lista_ciudades, producto_a_comprar, producto_a_vender);
}

BinTree<pair<int, int> > Barco::weighted_tree_rec(BinTree<string> mapa_rio, map<string, Ciudad>& lista_ciudades, int id_prod1, int id_prod2) {
    //Base case
    if(mapa_rio.empty()) {
        return BinTree<pair<int, int> > ();
    }

    if(mapa_rio.left().empty() and mapa_rio.right().empty()) {
        string id_ciudad = mapa_rio.value();
        Ciudad city = lista_ciudades[id_ciudad];
        pair<int, int> val = {0, 0};

        //prod1 es el producto a comprar, prod2 es el producto a vender
        if (city.contiene_producto(id_prod1)) {
            int cantidad_comprar = city.cantidad_necesaria(id_prod1);

            /*Comprobamos que la ciudad tiene exceso de producto que quiere comprar el barco*/
            if(cantidad_comprar > 0) {
                val.first += cantidad_comprar;
            }
        }

        if (city.contiene_producto(id_prod2)) {
            int cantidad_vender = city.cantidad_necesaria(id_prod2);

            /*Comprobamos que la ciudad tiene exceso de producto que quiere comprar el barco*/
            if(cantidad_vender < 0) {
                val.first += cantidad_vender;
            }
        }
        val.second = 1;

        return BinTree<pair<int, int> >(val, BinTree<pair<int, int> >(), BinTree<pair<int, int> >());
    }

    //Recursive case
    auto mapa_rio_left = weighted_tree_rec(mapa_rio.left(), lista_ciudades, id_prod1, id_prod2);
    auto mapa_rio_right = weighted_tree_rec(mapa_rio.right(), lista_ciudades, id_prod1, id_prod2);

    pair<int, int> val_left;
    val_left.first = mapa_rio_left.value().first;
    val_left.second = mapa_rio_left.value().second;

    pair<int, int> val_right;
    val_right.first = mapa_rio_right.value().first;
    val_right.second = mapa_rio_right.value().second;

    pair<int, int> val_node;
    //we have to add here a +=. THIS IMPLEMENTATION MAY BE WRONG
    val_node.first += max(val_right.first, val_left.first);
    val_node.second = 1+max(val_right.second, val_left.second);

    return BinTree<pair<int, int> > (val_node, mapa_rio_left, mapa_rio_right);
}