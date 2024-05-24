#include "Producto.hh"

Producto::Producto() {
    peso = 0;
    volumen = 0;
}

Producto::Producto(const int peso, const int volumen) {
    this->peso = peso;
    this->volumen = volumen;
}

int Producto::consultar_peso() const {
    return peso;
}

int Producto::consultar_volumen() const {
    return volumen;
}