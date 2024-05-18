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

    InfoProductos[id_prod].unidades = unidades;
    InfoProductos[id_prod].unidades_necesarias = unidades_necesarias;

    inventario[id_prod] = producto;

    double peso2 = producto.consultar_peso()*unidades;
    double volumen2 = producto.consultar_volumen()*unidades;

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
    inventario[id_producto] = producto;

    InfoProductos[id_producto].unidades = unidades;
    InfoProductos[id_producto].unidades_necesarias = unidades_necesarias;

    double peso2 = producto.consultar_peso()*unidades;
    double volumen2 = producto.consultar_volumen()*unidades;

    peso_total += peso2;
    volumen_total += volumen2;

    cout << peso_total << ' ' << volumen_total << endl;
}

bool Ciudad::contiene_producto(int id) const {
    map<int, Producto>::const_iterator it = inventario.find(id);

    return (it != inventario.end());
}

void Ciudad::modificar_producto(int id_producto, int unidades, int unidades_necesarias) {
    int cantidad = InfoProductos[id_producto].unidades;

    InfoProductos[id_producto].unidades = unidades;
    InfoProductos[id_producto].unidades_necesarias = unidades_necesarias;

    //If diff is negative, then the total reduces, otherwise there's a gain in weight and volume.
    int diff = unidades - cantidad;

    Producto product = inventario[id_producto];

    double peso2 = product.consultar_peso()*diff;
    double vol2 = product.consultar_volumen()*diff;

    peso_total += peso2;
    volumen_total += vol2;

    cout << peso_total << ' ' << volumen_total << endl;
}

void Ciudad::caract_producto(int id_producto) const {
    map<int, amount_products>::const_iterator it = InfoProductos.find(id_producto);

    cout << (it->second).unidades << ' ' << (it->second).unidades_necesarias << endl;
}

void Ciudad::quitar_producto(int id_producto) {

    int cantidad = InfoProductos[id_producto].unidades;
    double tp = inventario[id_producto].consultar_peso()*cantidad;
    double tv = inventario[id_producto].consultar_volumen()*cantidad;

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

    Producto product = consultar_producto(id_producto);

    double peso_elim = cantidad * product.consultar_peso();
    double vol_elim = cantidad * product.consultar_volumen();

    peso_total -= peso_elim;
    volumen_total -= vol_elim;
}

void Ciudad::adquisicion(int id_producto, int cantidad) {
    map<int, amount_products>::iterator it = InfoProductos.find(id_producto);

    (it->second).unidades += cantidad;

    Producto product = consultar_producto(id_producto);

    double peso_sum = cantidad * product.consultar_peso();
    double vol_sum = cantidad * product.consultar_volumen();

    peso_total += peso_sum;
    volumen_total += vol_sum;
}

Producto Ciudad::consultar_producto(int id_producto) {
    return inventario.at(id_producto);
}

void Ciudad::comerciar(Ciudad& city2) {
    map<int, amount_products>::iterator it1 = this->InfoProductos.begin();
    map<int, amount_products>::iterator it2 = city2.InfoProductos.begin();

    while(it1 != this->InfoProductos.end() and it2 != city2.InfoProductos.end()) {
        int id_prod1 = it1->first;
        int id_prod2 = it2->first;
        
        if(id_prod1 == id_prod2) {
            int cantidad_necesitada1 = this->cantidad_necesaria(id_prod1);
            int cantidad_necesitada2 = city2.cantidad_necesaria(id_prod2);

            if(cantidad_necesitada1 < 0 and cantidad_necesitada2 > 0) {
        //if 'cantidad' is negative, then the city needs products. If 'cantidad' is positive, then the city has an excess. 'cantidad' is the excess that the city has.
                this->adquisicion(id_prod1, cantidad_necesitada2);
                city2.reduccion(id_prod1, cantidad_necesitada2);
            }
            else if(cantidad_necesitada1 > 0 and cantidad_necesitada2 < 0) {
                this->reduccion(id_prod1, cantidad_necesitada1);
                city2.adquisicion(id_prod1, cantidad_necesitada1);
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