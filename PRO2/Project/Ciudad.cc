#include "Ciudad.hh"

Ciudad::Ciudad() {
    name = "";
    has_inventory = false;
    InfoProducts = map<int, amount_products> ();
}

Ciudad::Ciudad(string name) {
    this->name = name;
    has_inventory = false;
    InfoProducts = map<int, amount_products> ();
    inventory = map<int, Producto> ();
}

void Ciudad::add_inventory(int id_producto, int unidades, int unidades_necesarias, Producto product) {
    has_inventory = true;
    inventory[id_producto] = product;       //We add the product to the inventory of the city.

    amount_products needs;
    needs.amount = unidades;
    needs.necessary = unidades_necesarias;

    InfoProducts[id_producto] = needs;

    //Have to add the weight and the volume.
}