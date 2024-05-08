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