#include "Producto.hh"

Producto::Producto() {
    id = 0;
    peso = 0;
    volumen = 0;
}

Producto::Producto(int peso, int volumen, int i) {
    id = i+1;
    this->peso = peso;
    this->volumen = volumen;
}