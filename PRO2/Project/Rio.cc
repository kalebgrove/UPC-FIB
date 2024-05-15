#include "Rio.hh"

Rio::Rio() {
    lista_ciudades = map<string, Ciudad> ();
    Tree = map<string, pair<string, string> > ();
    mapa_rio = BinTree<string> ();
    lista_productos = vector<Producto> ();

    barco = Barco();
}

void Rio::leer_rio() {
    lista_ciudades.clear();

    mapa_rio = leer_rio_rec();
}

BinTree<string> Rio::leer_rio_rec() {
    string id_ciudad;
    cin >> id_ciudad;

    //Base case
    if(id_ciudad == "#") {
        return BinTree<string> ();
    }

    //Recursive case
    Ciudad c = Ciudad(id_ciudad);
    lista_ciudades[id_ciudad] = c;
    
    BinTree<string> tree_izq = leer_rio_rec();
    BinTree<string> tree_der = leer_rio_rec();

    return BinTree<string> (id_ciudad, tree_izq, tree_der);
}

void Rio::hacer_viaje() {
    barco.hacer_viaje(mapa_rio, lista_ciudades);
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

void Rio::modificar_barco(int producto_a_comprar, int producto_a_vender, double unidades_a_comprar, double unidades_a_vender) {
    barco = Barco(producto_a_comprar, producto_a_vender, unidades_a_comprar, unidades_a_vender);
}

void Rio::escribir_barco() const {
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

MAYBE CHANGE OPTIMIZATION FOR 'COMERCIAR' BY PUTTING IT INTO CIUDAD.HH
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

void Rio::redistribuir() {
    redistribuir_rec(mapa_rio);
}

void Rio::redistribuir_rec(BinTree<string> mapa_rio) {
    if(mapa_rio.empty()) return;

    if(not mapa_rio.left().empty() and not mapa_rio.right().empty()) {
        string id_main_city = mapa_rio.value();
        string left_city = mapa_rio.left().value();
        string right_city = mapa_rio.right().value();

        comerciar(id_main_city, left_city);
        comerciar(id_main_city, right_city);        
    }

    redistribuir_rec(mapa_rio.left());
    redistribuir_rec(mapa_rio.right());
}

Barco Rio::consultar_barco() {
    return barco;
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