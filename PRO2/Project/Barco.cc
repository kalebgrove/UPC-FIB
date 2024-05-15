#include "Barco.hh"

Barco::Barco() {
    producto_a_comprar = -1;
    producto_a_vender = -1;

    unidades_a_comprar = -1;
    unidades_a_vender = -1;

    ciudad_anterior = "";
}

Barco::Barco(int producto_a_comprar, int producto_a_vender, double unidades_a_comprar, double unidades_a_vender) {
    this->producto_a_comprar = producto_a_comprar;
    this->producto_a_vender = producto_a_vender;

    this->unidades_a_comprar = unidades_a_comprar;
    this->unidades_a_vender = unidades_a_vender;

    ciudad_anterior = "";
}

void Barco::escribir_barco() const {
    cout << producto_a_vender << ' ' << unidades_a_vender << endl;
    cout << producto_a_comprar << ' ' << unidades_a_comprar << endl;

    int n = ultima_ciudad_viaje.size();

    for(int i = 0; i < n; ++i) {
        cout << ultima_ciudad_viaje[i] << endl;
    }
}

void Barco::hacer_viaje(BinTree<string>& mapa_rio, map<string, Ciudad>& lista_ciudades) {
    
}