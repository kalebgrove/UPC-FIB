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

class Barco {
    private:

        int producto_a_comprar;
        int unidades_a_comprar;

        int producto_a_vender;
        int unidades_a_vender;

        vector<string> ultima_ciudad_viaje;

        string ciudad_anterior;

    public:
        Barco();

        Barco(int producto_a_comprar, int producto_a_vender, double unidades_a_comprar, double unidades_a_vender);

        void escribir_barco() const;

        void hacer_viaje(BinTree<string>& mapa_rio, map<string, Ciudad>& lista_ciudades);

        BinTree<pair<int, int> > weighted_tree_rec(BinTree<string> mapa_rio, map<string, Ciudad>& lista_ciudades, int id_prod1, int id_prod2);

        //Modificar los datos de un barco
        //Escribir los datos del barco
};
#endif