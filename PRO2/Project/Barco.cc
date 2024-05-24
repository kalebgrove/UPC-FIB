#include "Barco.hh"

Barco::Barco() {
    producto_a_comprar = -1;
    producto_a_vender = -1;

    unidades_a_comprar = -1;
    unidades_a_vender = -1;

    ultima_ciudad_viaje.clear();
}

Barco::Barco(const int producto_a_comprar, const int producto_a_vender, const int unidades_a_comprar, const int unidades_a_vender) {
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

    for(auto it = ultima_ciudad_viaje.begin(); it != ultima_ciudad_viaje.end(); ++it) {
        cout << *it << endl;
    }
}

void Barco::hacer_viaje(BinTree<string>& mapa_rio, map<string, Ciudad>& lista_ciudades, vector<Producto>& lista_productos) {

    int u_comprar = unidades_a_comprar;
    int u_vender = unidades_a_vender;

    list<string> ruta;

    BinTree<InfoNodo> travelled_tree = travelled_tree_rec(mapa_rio, lista_ciudades, u_comprar, u_vender, ruta);

    string last_city = "";

    if(travelled_tree.value().total_trato != 0) {
        ruta.push_front(mapa_rio.value());
        travel(ruta, lista_ciudades, lista_productos, u_comprar, u_vender, last_city);
    }
    if(last_city != "") ultima_ciudad_viaje.push_back(last_city);

    cout << travelled_tree.value().total_trato << endl;
}

BinTree<InfoNodo> Barco::travelled_tree_rec(BinTree<string> mapa_rio, map<string, Ciudad>& lista_ciudades, int unidades_comprar_barco, int unidades_vender_barco, list<string>& ruta) {
    //Base case
    if(mapa_rio.empty() or (unidades_comprar_barco <= 0 and unidades_vender_barco <= 0)) {
        return BinTree<InfoNodo> (InfoNodo(), BinTree<InfoNodo>(), BinTree<InfoNodo>());
    }

    InfoNodo node = InfoNodo();

    string id_ciudad = mapa_rio.value();
    Ciudad city = lista_ciudades[id_ciudad];

    if(city.contiene_producto(producto_a_comprar)) {
        int cantidad_vender = city.exceso(producto_a_comprar);
        
        //La ciudad quiere vender este producto.
        if(cantidad_vender > 0) {
            int cantidad = min(cantidad_vender, unidades_comprar_barco);

            node.venta = cantidad;
            node.total_venta = cantidad;
            unidades_comprar_barco -= cantidad;
        }
    }

    if(city.contiene_producto(producto_a_vender)) {
        int cantidad_comprar = city.exceso(producto_a_vender);

        if(cantidad_comprar < 0) {
            int cantidad = min(abs(cantidad_comprar), unidades_vender_barco);

            node.compra = cantidad;
            node.total_compra = cantidad;
            unidades_vender_barco -= cantidad;
        }
    }

    node.total_trato = node.compra + node.venta;

    list<string> rutaleft, rutaright;

    auto tleft = travelled_tree_rec(mapa_rio.left(), lista_ciudades, unidades_comprar_barco, unidades_vender_barco, rutaleft);
    auto tright = travelled_tree_rec(mapa_rio.right(), lista_ciudades, unidades_comprar_barco, unidades_vender_barco, rutaright);

    int totalleft = 0, totalright = 0;

    if(not tleft.empty()) {
        totalleft = tleft.value().total_trato;
    }

    if(not tright.empty()) {
        totalright = tright.value().total_trato;
    }

    if(totalleft == 0 and totalright == 0) {
        node.total_compra = node.compra;
        node.total_venta = node.venta;

        if(node.total_compra + node.total_venta > 0) node.altura = 1;
        else node.altura = 0;
    }
    else if(totalleft > totalright) {

        node.altura = tleft.value().altura + 1;
        node.total_trato += totalleft;
        node.total_compra += tleft.value().total_compra;
        node.total_venta += tleft.value().total_venta;

        ruta = rutaleft;
        ruta.push_front(mapa_rio.left().value());

    }
    else if(totalleft < totalright) {

        node.total_trato += totalright;
        node.altura = tright.value().altura + 1;
        node.total_compra += tright.value().total_compra;
        node.total_venta += tright.value().total_venta;

        ruta = rutaright;
        ruta.push_front(mapa_rio.right().value());

    }
    else {
        if(tleft.value().altura > tright.value().altura) {

            node.total_trato += totalright;
            node.altura = tright.value().altura + 1;
            node.total_compra += tright.value().total_compra;
            node.total_venta += tright.value().total_venta;

            ruta = rutaright;
            ruta.push_front(mapa_rio.right().value());

        }
        else {
            node.total_trato += totalleft;
            node.altura = tleft.value().altura + 1;
            node.total_compra += tleft.value().total_compra;
            node.total_venta += tleft.value().total_venta;

            ruta = rutaleft;
            ruta.push_front(mapa_rio.left().value());

        }
    }
    return BinTree<InfoNodo> (node, tleft, tright);
}

void Barco::travel(list<string>& ruta, map<string, Ciudad>& lista_ciudades, vector<Producto>& lista_productos, int u_comprar, int u_vender, string& last_city) {
    auto it = ruta.begin();

    while(it != ruta.end()) {

        string id_ciudad = *it;

        if(lista_ciudades[id_ciudad].contiene_producto(producto_a_comprar) and u_comprar > 0) {

            int exceso = lista_ciudades[id_ciudad].exceso(producto_a_comprar);
            
            if(exceso > 0) {
                int cantidad = min(exceso, u_comprar);

                lista_ciudades[id_ciudad].reduccion(producto_a_comprar, cantidad, lista_productos[producto_a_comprar - 1]);
                u_comprar -= cantidad;
            }
            last_city = id_ciudad;
        }

        if(lista_ciudades[id_ciudad].contiene_producto(producto_a_vender) and u_vender > 0) {

            int exceso = lista_ciudades[id_ciudad].exceso(producto_a_vender);
            
            if(exceso < 0) {
                int cantidad = min(abs(exceso), u_vender);

                lista_ciudades[id_ciudad].adquisicion(producto_a_vender, cantidad, lista_productos[producto_a_vender - 1]);
                u_vender -= cantidad;
            }
            last_city = id_ciudad;
        }
        ++it;
    }
}

void Barco::clear_travel() {
    ultima_ciudad_viaje.clear();
}