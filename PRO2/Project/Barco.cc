#include "Barco.hh"

Barco::Barco() {
    producto_a_comprar = -1;
    producto_a_vender = -1;

    unidades_a_comprar = -1;
    unidades_a_vender = -1;

    ultima_ciudad_viaje.clear();
}

Barco::Barco(int producto_a_comprar, int producto_a_vender, int unidades_a_comprar, int unidades_a_vender) {
    this->producto_a_comprar = producto_a_comprar;
    this->producto_a_vender = producto_a_vender;

    this->unidades_a_comprar = unidades_a_comprar;
    this->unidades_a_vender = unidades_a_vender;

    ultima_ciudad_viaje.clear();
}

void Barco::modificar_barco(int producto_a_comprar, int producto_a_vender, int unidades_a_comprar, int unidades_a_vender) {
    this->producto_a_comprar = producto_a_comprar;
    this->producto_a_vender = producto_a_vender;

    this->unidades_a_comprar = unidades_a_comprar;
    this->unidades_a_vender = unidades_a_vender;
}

void Barco::escribir_barco() const {
    cout << producto_a_comprar << ' ' << unidades_a_comprar << ' ' << producto_a_vender << ' ' << unidades_a_vender << endl;

    int n = ultima_ciudad_viaje.size();

    for(int i = 0; i < n; ++i) {
        cout << ultima_ciudad_viaje[i] << endl;
    }
}

void Barco::hacer_viaje(BinTree<string>& mapa_rio, map<string, Ciudad>& lista_ciudades) {

    BinTree<pair<int, int> > weighted_tree = weighted_tree_rec(mapa_rio, lista_ciudades);

    string last_city = "";

    int total = 0;

    //cout << producto_a_comprar << ' ' << producto_a_vender << endl;

    travel_tree(weighted_tree, mapa_rio, lista_ciudades, last_city, total);

    if(last_city != "") ultima_ciudad_viaje.push_back(last_city);

    cout << total << endl;

    BinTree<int> mod_tree = change_tree(weighted_tree);

    //mod_tree.setOutputFormat(BinTree<pair<int, int> >::VISUALFORMAT);
    //cout << mod_tree << endl;
}

BinTree<pair<int, int> > Barco::weighted_tree_rec(BinTree<string> mapa_rio, map<string, Ciudad>& lista_ciudades) {
    // Base case
    if(mapa_rio.empty()) {
        return BinTree<pair<int, int> > ();
    }
    
    int id_prod1 = this->producto_a_comprar;
    int id_prod2 = this->producto_a_vender;
    //We're at a leaf
    if(mapa_rio.left().empty() and mapa_rio.right().empty()) {
        string id_ciudad = mapa_rio.value();
        Ciudad city = lista_ciudades[id_ciudad];
        pair<int, int> val = {0, 0};

        //prod1 es el producto a comprar, prod2 es el producto a vender
        if (city.contiene_producto(id_prod1)) {
            int cantidad_comprar = city.cantidad_necesaria(id_prod1);

            //Comprobamos que la ciudad tiene exceso de producto que quiere comprar el barco
            if(cantidad_comprar > 0) {
                val.first += cantidad_comprar;
            }
        }

        if (city.contiene_producto(id_prod2)) {
            int cantidad_vender = city.cantidad_necesaria(id_prod2);

            //Comprobamos que la ciudad tiene exceso de producto que quiere comprar el barco
            if(cantidad_vender < 0) {
                val.first += abs(cantidad_vender);
            }
        }

        return BinTree<pair<int, int> >(val, BinTree<pair<int, int> >(), BinTree<pair<int, int> >());
    }

    //Recursive case
    auto mapa_rio_left = weighted_tree_rec(mapa_rio.left(), lista_ciudades);
    auto mapa_rio_right = weighted_tree_rec(mapa_rio.right(), lista_ciudades);

    pair<int, int> val_left;
    val_left.first = mapa_rio_left.value().first;
    val_left.second = mapa_rio_left.value().second;

    pair<int, int> val_right;
    val_right.first = mapa_rio_right.value().first;
    val_right.second = mapa_rio_right.value().second;

    string id_ciudad = mapa_rio.value();
    Ciudad city = lista_ciudades[id_ciudad];
    int total = 0;

    if(city.contiene_producto(id_prod1)) {
        int cantidad_comprar = city.cantidad_necesaria(id_prod1);

        if(cantidad_comprar > 0) {
            total += cantidad_comprar;
        }
    }

    if(city.contiene_producto(id_prod2)) {
        int cantidad_vender = city.cantidad_necesaria(id_prod2);

        if(cantidad_vender < 0) {
            total += abs(cantidad_vender);
        }
    }

    pair<int, int> val_node;

    val_node.first = max(val_right.first, val_left.first) + total;
    val_node.second = 1+max(val_right.second, val_left.second);

    return BinTree<pair<int, int> > (val_node, mapa_rio_left, mapa_rio_right);
}

void Barco::travel_tree(BinTree<pair<int, int> > weighted_tree, BinTree<string> mapa_rio, map<string, Ciudad>& lista_ciudades, string& last_city, int& total) {
    //We travel the tree in preorder: node and then we evaluate the left and right options.
    //Base case
    if(weighted_tree.empty()) {
        return;
    }

    //This second case of the base case is we analyze the node; we can assure this is true because the tree isn't empty (if statement beforehand)

    string id_ciudad = mapa_rio.value();
    auto it = lista_ciudades.find(id_ciudad);

    if(it == lista_ciudades.end()) {
        return;
    }

    if(it->second.contiene_producto(producto_a_comprar)){
        //Cantidad que quiere vender la ciudad = cantidad que quiere comprar el barco
        int cantidad_vender_ciudad = it->second.cantidad_necesaria(producto_a_comprar);

        //Si la cantidad es mayor que 0, entonces la ciudad tiene exceso del producto y puede venderlo. La cantidad almacenada es el exceso de la ciudad.
        //Pero puede ser que el exceso sea mayor a la cantidad que puede comprar el barco, entonces hay dos casos.
        if(cantidad_vender_ciudad > 0) {
            //Caso 1: Hay más exceso que cantidades que quiere comprar el barco.

            if(cantidad_vender_ciudad >= unidades_a_comprar) {
                total += unidades_a_comprar;
                it->second.reduccion(producto_a_comprar, unidades_a_comprar);
            }
            //Caso 2: el exceso es más pequeño que la cantidad que quiere comprar el barco.
            else {
                total += cantidad_vender_ciudad;
                it->second.reduccion(producto_a_comprar, cantidad_vender_ciudad);
            }
        }
        last_city = id_ciudad;
    }
    
    if(it->second.contiene_producto(producto_a_vender)){
        //Cantidad que quiere vender la ciudad = cantidad que quiere comprar el barco
        int cantidad_comprar_ciudad = it->second.cantidad_necesaria(producto_a_vender);

        //Si la cantidad es menor que 0, entonces la ciudad quiere comprar productos.
        if(cantidad_comprar_ciudad < 0) {
            
            //La ciudad quiere comprar más productos de los que están disponibles.
            if(abs(cantidad_comprar_ciudad) >= unidades_a_vender) {
                total += unidades_a_vender;
                it->second.adquisicion(producto_a_vender, unidades_a_vender);
            }
            else {
                total += abs(cantidad_comprar_ciudad);
                it->second.adquisicion(producto_a_vender, abs(cantidad_comprar_ciudad));
            }
        }
        last_city = id_ciudad;
    }

    //Recursive
    //Three cases: which side do we take: left or right?

    if((not weighted_tree.left().empty()) and (not weighted_tree.right().empty())){    
        if(weighted_tree.left().value().first > weighted_tree.right().value().first) {
            travel_tree(weighted_tree.left(), mapa_rio.left(), lista_ciudades, last_city, total);
        }
        else if(weighted_tree.left().value().first < weighted_tree.right().value().first) {
            travel_tree(weighted_tree.right(), mapa_rio.right(), lista_ciudades, last_city, total);
        }
        else {
            //Both values are the same;
            if(weighted_tree.left().value().second > weighted_tree.right().value().second) {
                //We take the shorter path
                travel_tree(weighted_tree.right(), mapa_rio.right(), lista_ciudades, last_city, total);
            }
            else if(weighted_tree.left().value().second <= weighted_tree.right().value().second) {
                travel_tree(weighted_tree.left(), mapa_rio.left(), lista_ciudades, last_city, total);
            }
        }
    }
    return;
}

void Barco::clear_travel() {
    ultima_ciudad_viaje.clear();
}

BinTree<int> Barco::change_tree(BinTree<pair<int, int> > weighted_tree) {
    if(weighted_tree.empty()) {
        return BinTree<int> ();
    }

    auto tleft = change_tree(weighted_tree.left());
    auto tright = change_tree(weighted_tree.right());

    auto value = weighted_tree.value().first;

    return BinTree<int> (value, tleft, tright);
}