#include "Ciudad.hh"

Ciudad::Ciudad() {
    name = "";
    InfoProductos = map<int, amount_products> ();
    inventario = map<int, Producto> ();

    peso_total = 0;
    volumen_total = 0;
}

Ciudad::Ciudad(string name) {
    this->name = name;
    InfoProductos = map<int, amount_products> ();
    inventario = map<int, Producto> ();

    peso_total = 0;
    volumen_total = 0;
}

void Ciudad::anadir_inventario(Producto& producto, int id_prod, int unidades, int unidades_necesarias) {
    InfoProductos = map<int, amount_products> ();
    inventario = map<int, Producto> ();

    amount_products new_product;
    new_product.unidades = unidades;
    new_product.unidades_necesarias = unidades_necesarias;

    InfoProductos[id_prod] = new_product;

    inventario[id_prod] = producto;

    double peso2 = producto.consultar_peso();
    double volumen2 = producto.consultar_volumen();

    peso_total += peso2;
    volumen_total += volumen2;
}

void Ciudad::escribir_ciudad() const {
    map<int, Producto>::const_iterator it = inventario.begin();
    map<int, amount_products>::const_iterator it2 = InfoProductos.begin();

    while(it != inventario.end() and it2 != InfoProductos.end()) {
        cout << it->first << ' ' << it2->second.unidades << ' ' << it2->second.unidades_necesarias << endl;
        ++it;
        ++it2;
    }

    cout << peso_total << ' ' << volumen_total << endl;
}

void Ciudad::poner_producto(Producto& producto, int id_producto, int unidades, int unidades_necesarias) {
    inventario[id_producto] = producto;

    amount_products info;
    info.unidades = unidades;
    info.unidades_necesarias = unidades_necesarias;

    InfoProductos[id_producto] = info;

    double peso2 = producto.consultar_peso();
    double volumen2 = producto.consultar_volumen();

    peso_total += peso2;
    volumen_total += volumen2;
}

bool Ciudad::contiene_producto(int id) const {
    map<int, Producto>::const_iterator it = inventario.find(id);

    return (it != inventario.end());
}

void Ciudad::modificar_producto(int id_producto, int unidades, int unidades_necesarias) {
    amount_products newInfo;
    newInfo.unidades = unidades;
    newInfo.unidades_necesarias = unidades_necesarias;

    InfoProductos[id_producto] = newInfo;

    recalculate_weight();
}

void Ciudad::recalculate_weight() {
    map<int, Producto>::iterator it = inventario.begin();
    double tp = 0;
    double tv = 0;
    int units = 0;
    while(it != inventario.end()) {
        units += InfoProductos[it->first].unidades;
        tp += inventario[it->first].consultar_peso();
        tv += inventario[it->first].consultar_volumen();
        ++it;
    }

    peso_total = units*tp;
    volumen_total = units*tv;
}

void Ciudad::caract_producto(int id_producto) const {
    map<int, amount_products>::const_iterator it = InfoProductos.find(id_producto);

    cout << (it->second).unidades << ' ' << (it->second).unidades_necesarias << endl;
}

void Ciudad::quitar_producto(int id_producto) {
    double tp = inventario[id_producto].consultar_peso();
    double tv = inventario[id_producto].consultar_volumen();

    peso_total -= tp;
    volumen_total -= tv;

    inventario.erase(id_producto);
    InfoProductos.erase(id_producto);

    cout << peso_total << ' ' << volumen_total << endl;
}

int Ciudad::mida_inventario() const {
    return inventario.size();
}

int Ciudad::consultar_iesimo_producto(int i) const {
    map<int, Producto>::const_iterator it = inventario.begin();

    for(int j = 0; j < i; ++j) ++it;

    return it->first;
}

int Ciudad::cantidad_necesaria(int id_producto) const {
    map<int, amount_products>::const_iterator it = InfoProductos.find(id_producto);

    int cantidad = (it->second).unidades - (it->second).unidades_necesarias;
    //if 'cantidad' is negative, then the city needs products. If 'cantidad' is positive, then the city has an excess.
    return cantidad;
}

void Ciudad::reduccion(int id_producto, int cantidad) {
    map<int, amount_products>::iterator it = InfoProductos.find(id_producto);

    (it->second).unidades -= cantidad;
}

void Ciudad::adquisicion(int id_producto, int cantidad) {
    map<int, amount_products>::iterator it = InfoProductos.find(id_producto);

    (it->second).unidades += cantidad;
}