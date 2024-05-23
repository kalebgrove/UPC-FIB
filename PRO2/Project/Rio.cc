#include "Rio.hh"

Rio::Rio() {
    lista_ciudades = map<string, Ciudad> ();
    mapa_rio = BinTree<string> ();
    lista_productos = vector<Producto> ();

    barco = Barco();
}

void Rio::leer_rio() {
    
    lista_ciudades.clear();

    mapa_rio = leer_rio_rec();

    barco.clear_travel();
}

BinTree<string> Rio::leer_rio_rec() {
    string id_ciudad;
    cin >> id_ciudad;

    //Base case
    if(id_ciudad == "#") {
        return BinTree<string> ();
    }

    //Recursive case
    lista_ciudades[id_ciudad] = Ciudad();
    
    BinTree<string> tree_izq = leer_rio_rec();
    BinTree<string> tree_der = leer_rio_rec();

    return BinTree<string> (id_ciudad, tree_izq, tree_der);
}

void Rio::iniciar_barco(const int id_prod1, const int id_prod2, const int cantidad1, const int cantidad2) {
    barco = Barco(id_prod1, id_prod2, cantidad1, cantidad2);
}

void Rio::hacer_viaje() {
    barco.hacer_viaje(mapa_rio, lista_ciudades, lista_productos);

}

/*BinTree<InfoNodo> Rio::travelled_tree_rec(const BinTree<string>& mapa_rio, int unidades_comprar_barco, int unidades_vender_barco) {
    //Base case
    if(mapa_rio.empty() or (unidades_comprar_barco == 0 and unidades_vender_barco == 0)) {
        return BinTree<InfoNodo> (InfoNodo(), BinTree<InfoNodo>(), BinTree<InfoNodo>());
    }

    InfoNodo node = InfoNodo();
    string id_ciudad = mapa_rio.value();
    auto it = lista_ciudades.find(id_ciudad);

    if(it->second.contiene_producto_ciudad(barco.prod_comprar())) {
        int cantidad_vender = it->second.exceso(barco.prod_comprar());
        
        //La ciudad quiere vender este producto.
        if(cantidad_vender > 0) {
            int cantidad = min(cantidad_vender, unidades_comprar_barco);

            node.venta = cantidad;
            node.total_venta += cantidad;
            unidades_comprar_barco -= cantidad;
        }
    }

    if(it->second.contiene_producto_ciudad(barco.prod_vender())) {
        int cantidad_comprar = it->second.exceso(barco.prod_vender());

        if(cantidad_comprar < 0) {
            int cantidad = min(abs(cantidad_comprar), unidades_vender_barco);

            node.compra = cantidad;
            node.total_compra += cantidad;
            unidades_vender_barco -= cantidad;
        }
    }

    node.total_trato += node.compra + node.venta;

    auto tleft = travelled_tree_rec(mapa_rio.left(), unidades_comprar_barco, unidades_vender_barco);
    auto tright = travelled_tree_rec(mapa_rio.right(), unidades_comprar_barco, unidades_vender_barco);

    int totalleft = 0, totalright = 0;

    if(not tleft.empty()) {
        totalleft = tleft.value().total_trato;
    }

    if(not tright.empty()) {
        totalright = tright.value().total_trato;
    }

    if(totalleft > totalright) {

        node.altura += tleft.value().altura + 1;
        node.total_trato += totalleft;
        node.total_compra += tleft.value().total_compra;
        node.total_venta += tleft.value().total_venta;

        return BinTree<InfoNodo> (node, tleft, tright);
    }
    else if(totalleft < totalright) {
        node.total_trato += totalright;
        node.altura += tright.value().altura + 1;
        node.total_compra += tright.value().total_compra;
        node.total_venta += tright.value().total_venta;

        return BinTree<InfoNodo> (node, tleft, tright);
    }
    else {
        
        node.altura += min(tleft.value().altura, tright.value().altura) + 1;

        if(tleft.value().altura > tright.value().altura) {
            node.total_trato += totalright;
            node.total_compra += tright.value().total_compra;
            node.total_venta += tright.value().total_venta;

            return BinTree<InfoNodo> (node, tleft, tright);
        }
        else {
            node.total_trato += totalleft;
            node.total_compra += tleft.value().total_compra;
            node.total_venta += tleft.value().total_venta;

            return BinTree<InfoNodo> (node, tleft, tright);
        }
    }
}

void Rio::travel_tree(const BinTree<InfoNodo>& travelled_tree, const BinTree<string>& mapa_rio, string& last_city) {
    //Base case
    if(travelled_tree.empty() or mapa_rio.empty()) return;

    string id_ciudad = mapa_rio.value();

    if(travelled_tree.value().venta > 0 and barco.un_comprar() > 0) {

        lista_ciudades[id_ciudad].reduccion(barco.prod_comprar(), travelled_tree.value().venta, lista_productos[barco.prod_comprar() - 1]);

        last_city = id_ciudad;
    }

    if(travelled_tree.value().compra > 0 and barco.un_vender() > 0) {

        lista_ciudades[id_ciudad].adquisicion(barco.prod_vender(), travelled_tree.value().compra, lista_productos[barco.prod_vender() - 1]);

        last_city = id_ciudad;
    }


    if(not travelled_tree.left().empty() and not travelled_tree.right().empty()) {
        
        if(travelled_tree.left().value().total_trato < travelled_tree.right().value().total_trato) {
            travel_tree(travelled_tree.right(), mapa_rio.right(), last_city);
        }
        else if(travelled_tree.left().value().total_trato > travelled_tree.right().value().total_trato) {
            travel_tree(travelled_tree.left(), mapa_rio.left(), last_city);
        }
        else {
            if(travelled_tree.left().value().altura > travelled_tree.right().value().altura) {
                travel_tree(travelled_tree.right(), mapa_rio.right(), last_city);
            }
            else {
                travel_tree(travelled_tree.left(), mapa_rio.left(), last_city);
            }
        }
    }
    return;
}*/

bool Rio::existe_ciudad(string id) const {
    map<string, Ciudad>::const_iterator it = lista_ciudades.find(id);

    return (it != lista_ciudades.end());
}

bool Rio::existe_producto(int id) const {
    return (id <= lista_productos.size() and id > 0);
}

void Rio::leer_inventario(string id_ciudad, int id_producto, int unidades, int unidades_necesarias) {

    lista_ciudades[id_ciudad].anadir_inventario(lista_productos[id_producto-1], id_producto, unidades, unidades_necesarias);
}

void Rio::modificar_barco(int producto_a_comprar, int producto_a_vender, int unidades_a_comprar, int unidades_a_vender) {
    barco.modificar_barco(producto_a_comprar, producto_a_vender, unidades_a_comprar, unidades_a_vender);
}

void Rio::escribir_barco() const {
    barco.escribir_barco();
}

void Rio::consultar_num() const {
    cout << lista_productos.size() << endl;
}

void Rio::escribir_producto(int id_producto) const {

    cout << lista_productos[id_producto-1].consultar_peso() << ' ' << lista_productos[id_producto-1].consultar_volumen() << endl;
}

void Rio::escribir_ciudad(string id) const {
    //Write the product id's and the amount and necessary amount.
    
    lista_ciudades.at(id).escribir_ciudad();
}

void Rio::poner_producto(string id_ciudad, int id_producto, int unidades, int unidades_necesarias) {

    lista_ciudades[id_ciudad].poner_producto_ciudad(lista_productos[id_producto-1], id_producto, unidades, unidades_necesarias);
}

bool Rio::existe_producto_ciudad(string id_ciudad, int id) const {

    return lista_ciudades.at(id_ciudad).contiene_producto_ciudad(id);

}

void Rio::modificar_producto(string id_ciudad, int id_producto, int unidades, int unidades_necesarias) {

    lista_ciudades[id_ciudad].modificar_producto_ciudad(id_producto, unidades, unidades_necesarias, lista_productos[id_producto-1]);
}

void Rio::quitar_producto(string id_ciudad, int id_producto) {
    
    lista_ciudades[id_ciudad].quitar_producto_ciudad(id_producto, lista_productos[id_producto-1]);
}

void Rio::caract_producto(string id_ciudad, int id_producto) const {
    lista_ciudades.at(id_ciudad).caract_producto_ciudad(id_producto);
}

void Rio::comerciar(string id_ciudad1, string id_ciudad2) {

    auto it_ciudad1 = lista_ciudades.find(id_ciudad1);
    auto it_ciudad2 = lista_ciudades.find(id_ciudad2);

    map<int, amount_products> inventario1 = it_ciudad1->second.inventario_ciudad();
    map<int, amount_products> inventario2 = it_ciudad2->second.inventario_ciudad();

    auto it = inventario1.begin();
    auto it2 = inventario2.begin();

    while(it != inventario1.end() and it2 != inventario2.end()) {

        if(it->first == it2->first) {
            int cantidad_necesitada1 = it_ciudad1->second.exceso(it->first);
            int cantidad_necesitada2 = it_ciudad2->second.exceso(it2->first);

            if(cantidad_necesitada1 < 0 and cantidad_necesitada2 > 0) {
        //if 'cantidad' is negative, then the city needs products. If 'cantidad' is positive, then the city has an excess. 'cantidad' is the excess that the city has.
                
                int cantidad = min(abs(cantidad_necesitada1), cantidad_necesitada2);

                it_ciudad1->second.adquisicion(it->first, cantidad, lista_productos[it->first - 1]);
                it_ciudad2->second.reduccion(it->first, cantidad, lista_productos[it2->first - 1]);
            }
            else if(cantidad_necesitada1 > 0 and cantidad_necesitada2 < 0) {
                
                int cantidad = min(abs(cantidad_necesitada2), cantidad_necesitada1);

                it_ciudad1->second.reduccion(it->first, cantidad, lista_productos[it->first - 1]);
                it_ciudad2->second.adquisicion(it->first, cantidad, lista_productos[it2->first - 1]);
            }

            ++it;
            ++it2;
        }
        else if(it->first < it2->first) {
            ++it;
        }
        else {
            ++it2;
        }
    }

    //lista_ciudades[id_ciudad1].comerciar_ciudad(lista_ciudades[id_ciudad2], lista_productos);
}

void Rio::redistribuir() {
    redistribuir_rec(mapa_rio);
}

void Rio::redistribuir_rec(const BinTree<string>& mapa_rio) {
    if(mapa_rio.left().empty() or mapa_rio.right().empty()) return;
    
    string id_main_city = mapa_rio.value();

    string left_city = mapa_rio.left().value();
    comerciar(id_main_city, left_city);

    string right_city = mapa_rio.right().value();
    comerciar(id_main_city, right_city);

    redistribuir_rec(mapa_rio.left());
    redistribuir_rec(mapa_rio.right());

}

void Rio::error_no_ciudad() const {
    cout << ERR_NO_CIUDAD << endl;
}

void Rio::error_no_producto() const {
    cout << ERR_NO_PRODUCTO << endl;
}

void Rio::error_no_producto_ciudad() const {
    cout << ERR_NO_PRODUCTO_CIUDAD << endl;
}

void Rio::error_ciudad_producto() const {
    cout << ERR_CIUDAD_TIENE_PRODUCTO << endl;
}

void Rio::error_mismo_producto() const{
    cout << ERR_MISMO_PRODUCTO_COMPRAVENDA << endl;
}

void Rio::error_misma_ciudad() const {
    cout << ERR_MISMA_CIUDAD << endl;
}

void Rio::leer_productos(int peso, int volumen) {
    Producto product = Producto(peso, volumen);
    lista_productos.push_back(product);
}

void Rio::clear_inventory(string id_ciudad) {

    lista_ciudades[id_ciudad].clear_inventory();
}