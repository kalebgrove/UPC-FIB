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

void Rio::agregar_productos(int peso, int volumen) {
    Producto producto = Producto(peso, volumen);

    lista_productos.push_back(producto);
}

void Rio::escribir_producto(int id_producto) const {

    cout << lista_productos[id_producto-1].consultar_peso() << ' ' << lista_productos[id_producto-1].consultar_volumen() << endl;
}

void Rio::escribir_ciudad(string id) const {
    //Write the product id's and the amount and necessary amount.
    
    lista_ciudades.at(id).escribir_ciudad();
}

void Rio::poner_producto(string id_ciudad, int id_producto, int unidades, int unidades_necesarias) {

    lista_ciudades[id_ciudad].poner_producto(lista_productos[id_producto-1], id_producto, unidades, unidades_necesarias);
}

bool Rio::existe_producto_ciudad(string id_ciudad, int id) const {

    return lista_ciudades.at(id_ciudad).contiene_producto(id);

}

void Rio::modificar_producto(string id_ciudad, int id_producto, int unidades, int unidades_necesarias) {

    lista_ciudades[id_ciudad].modificar_producto(id_producto, unidades, unidades_necesarias, lista_productos[id_producto-1]);
}

void Rio::quitar_producto(string id_ciudad, int id_producto) {
    
    lista_ciudades[id_ciudad].quitar_producto(id_producto, lista_productos[id_producto-1]);
}

void Rio::caract_producto(string id_ciudad, int id_producto) const {
    lista_ciudades.at(id_ciudad).caract_producto(id_producto);
}

void Rio::comerciar(string id_ciudad1, string id_ciudad2) {

    lista_ciudades[id_ciudad1].comerciar(lista_ciudades[id_ciudad2], lista_productos);
}

void Rio::redistribuir() {
    redistribuir_rec(mapa_rio);
}

void Rio::redistribuir_rec(BinTree<string> mapa_rio) {
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

void Rio::print_tree() {
    mapa_rio.setOutputFormat(BinTree<pair<int, int> >::VISUALFORMAT);
    cout << mapa_rio << endl;
}

void Rio::clear_inventory(string id_ciudad) {

    lista_ciudades[id_ciudad].clear_inventory();
}