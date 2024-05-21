#include "Producto.hh"

Producto::Producto() {
    peso = 0;
    volumen = 0;
}

Producto::Producto(int peso, int volumen) {
    this->peso = peso;
    this->volumen = volumen;
}

int Producto::consultar_peso() const {
    return peso;
}

int Producto::consultar_volumen() const {
    return volumen;
}