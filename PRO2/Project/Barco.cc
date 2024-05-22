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

    int unidades_comprar_barco = unidades_a_comprar;
    int unidades_vender_barco = unidades_a_vender;

    BinTree<pair<int, int> > diff_tree = weighted_tree_rec(mapa_rio, lista_ciudades, unidades_comprar_barco, unidades_vender_barco);

    string last_city = "";

    //BinTree<int> mod_tree = change_tree(diff_tree);

    //mod_tree.setOutputFormat(BinTree<pair<int, int> >::VISUALFORMAT);
    //cout << mod_tree << endl;

    travel(diff_tree, mapa_rio, lista_ciudades, last_city);

    if(last_city != "") ultima_ciudad_viaje.push_back(last_city);

    int total = 0;

    if(not diff_tree.empty()) {
        total = diff_tree.value().first;
    }

    cout << total << endl;
}

//Two pairs: first.first is going to contain the accumulation of the trades done during the trip. The second pair is going to contain the height

BinTree<pair<int, int> > Barco::weighted_tree_rec(BinTree<string> mapa_rio, map<string, Ciudad>& lista_ciudades, int unidades_comprar_barco, int unidades_vender_barco) {
    //Base case
    if(unidades_comprar_barco == 0 and unidades_vender_barco == 0) {
        return BinTree<pair<int, int> > (make_pair(0,0), BinTree<pair<int, int> > (), BinTree<pair<int, int> > ());
    }

    if(mapa_rio.empty()) {
        return BinTree<pair<int, int> > (make_pair(0,0), BinTree<pair<int, int> > (), BinTree<pair<int, int> > ());
    }

    int trato = 0;
    string id_ciudad = mapa_rio.value();
    Ciudad city = lista_ciudades[id_ciudad];

    if(city.contiene_producto(producto_a_comprar) and unidades_comprar_barco > 0) {
        int cantidad = city.exceso(producto_a_comprar);

        if(cantidad > 0) {
            if(cantidad < unidades_comprar_barco) {
                trato += cantidad;
                unidades_comprar_barco -= cantidad;
            }
            else {
                trato += unidades_comprar_barco;
                unidades_comprar_barco = 0;
            }
        }
    }

    if(city.contiene_producto(producto_a_vender) and unidades_vender_barco > 0) {
        int cantidad = city.exceso(producto_a_vender);

        if(cantidad < 0) {
            if(abs(cantidad) < unidades_vender_barco) {
                trato += abs(cantidad);
                unidades_vender_barco -= abs(cantidad);
            }
            else {
                trato += unidades_vender_barco;
                unidades_vender_barco = 0;
            }
        }
    }

    auto tleft = weighted_tree_rec(mapa_rio.left(), lista_ciudades, unidades_comprar_barco, unidades_vender_barco);
    auto tright = weighted_tree_rec(mapa_rio.right(), lista_ciudades, unidades_comprar_barco, unidades_vender_barco);

    if(tleft.value().first < tright.value().first) { 
        return BinTree<pair<int, int> > (make_pair(trato+tright.value().first, tright.value().second + 1), tleft, tright);
    }
    else if(tleft.value().first > tright.value().first) {
        return BinTree<pair<int, int> > (make_pair(trato+tleft.value().first, tleft.value().second + 1), tleft, tright);
    }
    else {
        if(tleft.value().second > tright.value().second) {
            return BinTree<pair<int, int> > (make_pair(trato+tright.value().first, tright.value().second + 1), tleft, tright);
        }
        else {
            return BinTree<pair<int, int> > (make_pair(trato+tleft.value().first, tleft.value().second + 1), tleft, tright);
        }
    }
}

void Barco::travel(BinTree<pair<int, int> > diff_tree, BinTree<string> mapa_rio, map<string, Ciudad>& lista_ciudades, string& last_city) {
    //Base case
    if(diff_tree.empty() or mapa_rio.empty()) return;

    if(diff_tree.value().second == 0) {
        return;
    }

    string id_ciudad = mapa_rio.value();
    auto it = lista_ciudades.find(id_ciudad);
    //cout << last_city << endl;

    if(it == lista_ciudades.end()) {
        return;
    }

    if(it->second.contiene_producto(producto_a_comprar) and unidades_a_comprar > 0) {
        int cantidad = it->second.exceso(producto_a_comprar);

        if(cantidad > 0) {
            if(cantidad < unidades_a_comprar) {
                it->second.reduccion(producto_a_comprar, cantidad);
            }
            else {
                it->second.reduccion(producto_a_comprar, unidades_a_comprar);
            }
            last_city = it->first;
        }
    }

    if(it->second.contiene_producto(producto_a_vender) and unidades_a_vender > 0) {
        int cantidad = it->second.exceso(producto_a_vender);

        if(cantidad < 0) {
            if(abs(cantidad) < unidades_a_vender) {
                it->second.adquisicion(producto_a_vender, abs(cantidad));
            }
            else {
                it->second.adquisicion(producto_a_vender, unidades_a_vender);
            }
            last_city = it->first;
        }
    }
    
    //Recursive case
    if(not diff_tree.left().empty() and not diff_tree.right().empty()) {
        
        if(diff_tree.left().value().first < diff_tree.right().value().first) {
            travel(diff_tree.right(), mapa_rio.right(), lista_ciudades, last_city);
        }
        else if(diff_tree.left().value().first > diff_tree.right().value().first) {
            travel(diff_tree.left(), mapa_rio.left(), lista_ciudades, last_city);
        }
        else {
            if(diff_tree.left().value().second > diff_tree.right().value().second) {
                travel(diff_tree.right(), mapa_rio.right(), lista_ciudades, last_city);
            }
            else {
                travel(diff_tree.left(), mapa_rio.left(), lista_ciudades, last_city);
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