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

void Rio::leer_inventario(string id_ciudad, int id_producto, int unidades, int unidades_necesarias) {
    Ciudad city = consultar_ciudad(id_ciudad);
    Producto producto = consultar_producto(id_producto);
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

void Rio::poner_producto(string id_ciudad, int id_producto, int unidades, int unidades_necesarias) {
    Ciudad city = consultar_ciudad(id_ciudad);
    Producto producto = consultar_producto(id_producto);

    city.poner_producto(producto, id_producto, unidades, unidades_necesarias);
}

bool Rio::existe_producto_ciudad(string id_ciudad, int id) const {
    Ciudad city = consultar_ciudad(id_ciudad);
    return city.contiene_producto(id);
}

void Rio::modificar_producto(string id_ciudad, int id_producto, int unidades, int unidades_necesarias) {
    Ciudad city = consultar_ciudad(id_ciudad);
    city.modificar_producto(id_producto, unidades, unidades_necesarias);
}

void Rio::quitar_producto(string id_ciudad, int id_producto) {
    Ciudad city = consultar_ciudad(id_ciudad);
    city.quitar_producto(id_producto);
}

void Rio::caract_producto(string id_ciudad, int id_producto) const {
    Ciudad city = consultar_ciudad(id_ciudad);
    city.caract_producto(id_producto);
}

void Rio::comerciar(string id_ciudad1, string id_ciudad2) {
    Ciudad city1 = consultar_ciudad(id_ciudad1);
    Ciudad city2 = consultar_ciudad(id_ciudad2);

    int n = city1.mida_inventario();

    for(int i = 0; i < n; ++i) {
        int id_producto1 = city1.consultar_iesimo_producto(i);
        
        if(city2.contiene_producto(id_producto1)) {
            int cantidad_necesitada1 = city1.cantidad_necesaria(id_producto1);
            int cantidad_necesitada2 = city2.cantidad_necesaria(id_producto1);

            if(cantidad_necesitada1 < 0 and cantidad_necesitada2 > 0) {
        //if 'cantidad' is negative, then the city needs products. If 'cantidad' is positive, then the city has an excess. 'cantidad' is the excess that the city has.
                city1.adquisicion(id_producto1, cantidad_necesitada2);
                city2.reduccion(id_producto1, cantidad_necesitada2);
            }
            else if(cantidad_necesitada1 > 0 and cantidad_necesitada2 < 0) {
                city1.reduccion(id_producto1, cantidad_necesitada1);
                city2.adquisicion(id_producto1, cantidad_necesitada1);
            }
        }
    }
}