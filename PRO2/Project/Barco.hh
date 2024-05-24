/** @file Barco.hh
    @brief Especificación de la clase Barco 
*/

#ifndef _BARCO_HH_
#define _BARCO_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include "Producto.hh"
#include "Ciudad.hh"
#include "BinTree.hh"
#include <map>
#include <list>
#include <vector>
#endif

/*The boat is the object that allows commerce between two cities. The boat will contain an additional inventory, with its own products, 
such that it is allows to purchase and sell two DIFFERENT products.*/

struct InfoNodo {
    int altura;
    int total_compra;
    int total_venta;
    int total_trato;
    int compra;
    int venta;

    InfoNodo() {
        altura = 0;
        total_compra = 0;
        total_venta = 0;
        total_trato = 0;
        compra = 0;
        venta = 0;
    }
};

class Barco {
    private:

        int producto_a_comprar;
        int unidades_a_comprar;

        int producto_a_vender;
        int unidades_a_vender;

        list<string> ultima_ciudad_viaje;

    public:
        Barco();

        Barco(const int producto_a_comprar, const int producto_a_vender, const int unidades_a_comprar, const int unidades_a_vender);

        void escribir_barco() const;

        void modificar_barco(int producto_a_comprar, int producto_a_vender, int unidades_a_comprar, int unidades_a_vender);

        void hacer_viaje(BinTree<string>& mapa_rio, map<string, Ciudad>& lista_ciudades, vector<Producto>& lista_productos);

        BinTree<InfoNodo> travelled_tree_rec(BinTree<string> mapa_rio, map<string, Ciudad>& lista_ciudades, int unidades_comprar_barco, int unidades_vender_barco, list<string>& ruta);

        void travel(list<string>& ruta, map<string, Ciudad>& lista_ciudades, vector<Producto>& lista_productos, int u_comprar, int u_vender, string& last_city);

        void clear_travel();
};
#endif