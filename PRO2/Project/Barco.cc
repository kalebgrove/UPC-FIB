#include "Barco.hh"

Barco::Barco() {
    producto_a_comprar = -1;
    producto_a_vender = -1;

    unidades_a_comprar = -1;
    unidades_a_vender = -1;

    num_viajes = 0;
    ciudad_anterior = "";
}

Barco::Barco(int producto_a_comprar, int producto_a_vender, int unidades_a_comprar, int unidades_a_vender) {
    this->producto_a_comprar = producto_a_comprar;
    this->producto_a_vender = producto_a_vender;

    this->unidades_a_comprar = unidades_a_comprar;
    this->unidades_a_vender = unidades_a_vender;

    num_viajes = 0;
    ciudad_anterior = "";
}