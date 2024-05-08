#include "Producto.hh"

Producto::Producto() {
    peso = 0;
    volumen = 0;
}

Producto::Producto(double peso, double volumen) {
    this->peso = peso;
    this->volumen = volumen;
}

double Producto::consultar_peso() const {
    return peso;
}

double Producto::consultar_volumen() const {
    return volumen;
}