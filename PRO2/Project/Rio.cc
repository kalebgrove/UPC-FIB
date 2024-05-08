#include "Rio.hh"

Rio::Rio() {
    map<string, Ciudad> lista_ciudades = map<string, Ciudad> ();
    vector<Producto> lista_productos = vector<Producto> ();

    Barco barco = Barco();
}

bool Rio::existe_ciudad(string id) const {
    map<string, Ciudad>::const_iterator it = lista_ciudades.find(id);

    return (it != lista_ciudades.end());
}

bool Rio::existe_producto(int id) const {
    return (id < lista_productos.size());
}

Ciudad Rio::consultar_ciudad(string id) const {
    Ciudad city = lista_ciudades.at(id);

    return city;
}

Producto Rio::consultar_producto(int id) const {
    Producto producto = lista_productos[id];

    return producto;
}

void Rio::leer_inventario(Ciudad& city, Producto& producto, int id_producto, int unidades, int unidades_necesarias) {
    Producto producto = lista_productos.at(id_producto);
    city.anadir_inventario(producto, id_producto, unidades, unidades_necesarias);
}

void Rio::modificar_barco(Barco& barco, int producto_a_comprar, int producto_a_vender, double unidades_a_comprar, double unidades_a_vender) {
    barco = Barco(producto_a_comprar, producto_a_vender, unidades_a_comprar, unidades_a_vender);
}

void Rio::escribir_barco(Barco& barco) const {
    barco.escribir_barco();
}

void Rio::consultar_num() const {
    cout << lista_productos.size() << endl;
}

void Rio::agregar_productos(double peso, double volumen) {
    Producto producto = Producto(peso, volumen);

    lista_productos.push_back(producto);
}

void Rio::escribir_producto(int id_producto) const {
    Producto producto = lista_productos[id_producto];

    cout << producto.consultar_peso() << ' ' << producto.consultar_volumen();
}

void Rio::escribir_ciudad(string id) const {
    //Write the product id's and the amount and necessary amount.
    Ciudad city = consultar_ciudad(id);
    city.escribir_ciudad();
}

void Rio::poner_producto(Ciudad& city, int id_producto, int unidades, int unidades_necesarias) {
    Producto producto = consultar_producto(id_producto);
    city.poner_producto(producto, id_producto, unidades, unidades_necesarias);
}

bool Rio::existe_producto_ciudad(Ciudad& city, int id) const {
    return city.contiene_producto(id);
}