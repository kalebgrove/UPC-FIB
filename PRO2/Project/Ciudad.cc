#include "Ciudad.hh"

Ciudad::Ciudad() {
    InfoProductos = map<int, amount_products> ();

    peso_total = 0;
    volumen_total = 0;
}

void Ciudad::anadir_inventario(Producto& producto, int id_prod, int unidades, int unidades_necesarias) {

    InfoProductos[id_prod].unidades = unidades;
    InfoProductos[id_prod].unidades_necesarias = unidades_necesarias;

    int peso2 = producto.consultar_peso()*unidades;
    int volumen2 = producto.consultar_volumen()*unidades;

    peso_total += peso2;
    volumen_total += volumen2;
}

void Ciudad::escribir_ciudad() const {
    map<int, amount_products>::const_iterator it2 = InfoProductos.begin();

    while(it2 != InfoProductos.end()) {
        cout << it2->first << ' ' << it2->second.unidades << ' ' << it2->second.unidades_necesarias << endl;
        ++it2;
    }

    cout << peso_total << ' ' << volumen_total << endl;
}

void Ciudad::poner_producto(Producto& producto, int id_producto, int unidades, int unidades_necesarias) {

    InfoProductos[id_producto].unidades = unidades;
    InfoProductos[id_producto].unidades_necesarias = unidades_necesarias;

    int peso2 = producto.consultar_peso()*unidades;
    int volumen2 = producto.consultar_volumen()*unidades;

    peso_total += peso2;
    volumen_total += volumen2;

    cout << peso_total << ' ' << volumen_total << endl;
}

bool Ciudad::contiene_producto(int id) const {
    map<int, amount_products>::const_iterator it = InfoProductos.find(id);

    return (it != InfoProductos.end());
}

void Ciudad::modificar_producto(int id_producto, int unidades, int unidades_necesarias, Producto& product) {
    int cantidad = InfoProductos[id_producto].unidades;

    InfoProductos[id_producto].unidades = unidades;
    InfoProductos[id_producto].unidades_necesarias = unidades_necesarias;

    //If diff is negative, then the total reduces, otherwise there's a gain in weight and volume.
    int diff = unidades - cantidad;

    int peso2 = product.consultar_peso()*diff;
    int vol2 = product.consultar_volumen()*diff;

    peso_total += peso2;
    volumen_total += vol2;

    cout << peso_total << ' ' << volumen_total << endl;
}

void Ciudad::caract_producto(int id_producto) const {
    map<int, amount_products>::const_iterator it = InfoProductos.find(id_producto);

    cout << (it->second).unidades << ' ' << (it->second).unidades_necesarias << endl;
}

void Ciudad::quitar_producto(int id_producto, Producto& product) {

    int cantidad = InfoProductos[id_producto].unidades;

    int tp = product.consultar_peso()*cantidad;
    int tv = product.consultar_volumen()*cantidad;

    peso_total -= tp;
    volumen_total -= tv;

    InfoProductos.erase(id_producto);

    cout << peso_total << ' ' << volumen_total << endl;
}

int Ciudad::mida_inventario() const {
    return InfoProductos.size();
}

int Ciudad::exceso(int id_producto) const {
    map<int, amount_products>::const_iterator it = InfoProductos.find(id_producto);

    int cantidad = (it->second).unidades - (it->second).unidades_necesarias;
    //if 'cantidad' is negative, then the city needs products. If 'cantidad' is positive, then the city has an excess.
    return cantidad;
}

void Ciudad::reduccion(int id_producto, int cantidad, Producto& product) {
    map<int, amount_products>::iterator it = InfoProductos.find(id_producto);

    (it->second).unidades -= cantidad;

    int peso_elim = cantidad * product.consultar_peso();
    int vol_elim = cantidad * product.consultar_volumen();

    peso_total -= peso_elim;
    volumen_total -= vol_elim;
}

void Ciudad::adquisicion(int id_producto, int cantidad, Producto& product) {
    map<int, amount_products>::iterator it = InfoProductos.find(id_producto);

    (it->second).unidades += cantidad;

    int peso_sum = cantidad * product.consultar_peso();
    int vol_sum = cantidad * product.consultar_volumen();

    peso_total += peso_sum;
    volumen_total += vol_sum;
}

void Ciudad::comerciar(Ciudad& city2, vector<Producto>& lista_productos) {
    map<int, amount_products>::iterator it1 = this->InfoProductos.begin();
    map<int, amount_products>::iterator it2 = city2.InfoProductos.begin();

    while(it1 != this->InfoProductos.end() and it2 != city2.InfoProductos.end()) {
        int id_prod1 = it1->first;
        int id_prod2 = it2->first;
        
        if(id_prod1 == id_prod2) {
            int cantidad1 = this->exceso(id_prod1);
            int cantidad2 = city2.exceso(id_prod2);

            if(cantidad1 < 0 and cantidad2 > 0) {
        //if 'cantidad' is negative, then the city needs products. If 'cantidad' is positive, then the city has an excess. 'cantidad' is the excess that the city has.
                
                int cantidad = min(abs(cantidad1), cantidad2);

                this->adquisicion(id_prod1, cantidad, lista_productos[id_prod1 - 1]);
                city2.reduccion(id_prod1, cantidad, lista_productos[id_prod1 - 1]);
            }
            else if(cantidad1 > 0 and cantidad2 < 0) {
                
                int cantidad = min(abs(cantidad2), cantidad1);

                this->reduccion(id_prod1, cantidad, lista_productos[id_prod1 - 1]);
                city2.adquisicion(id_prod1, cantidad, lista_productos[id_prod1 - 1]);
            }

            ++it1;
            ++it2;
        }
        else if(id_prod1 < id_prod2) {
            ++it1;
        }
        else {
            ++it2;
        }
    }
}

void Ciudad::clear_inventory() {
    InfoProductos.clear();

    peso_total = 0;
    volumen_total = 0;
}