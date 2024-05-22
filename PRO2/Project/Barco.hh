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

        list<string> ultima_ciudad_viaje;

        bool ini;

    public:
        Barco();

        Barco(int producto_a_comprar, int producto_a_vender, int unidades_a_comprar, int unidades_a_vender);

        void escribir_barco() const;

        void modificar_barco(int producto_a_comprar, int producto_a_vender, int unidades_a_comprar, int unidades_a_vender);

        //void hacer_viaje(const BinTree<string>& mapa_rio, map<string, Ciudad>& lista_ciudades, vector<Producto>& lista_productos);

        void modify_list(string last_city);

        void clear_travel();

        int prod_comprar();

        int prod_vender();

        int un_comprar();

        int un_vender();

        bool inicializado();

        //BinTree<pair<int, int> > weighted_tree_rec(BinTree<string> mapa_rio, map<string, Ciudad>& lista_ciudades);

        //void travel_tree(BinTree<pair<int, int> > weighted_tree, BinTree<string> mapa_rio, map<string, Ciudad>& lista_ciudades, string& last_city, int& total);

        //BinTree<InfoNodo> travelled_tree_rec(const BinTree<string>& mapa_rio, map<string, Ciudad>& lista_ciudades, int unidades_comprar_barco, int unidades_vender_barco);

        //void travel_tree(const BinTree<InfoNodo>& travelled_tree, const BinTree<string>& mapa_rio, map<string, Ciudad>& lista_ciudades, string& last_city, vector<Producto>& product);

        //BinTree<int> change_tree(BinTree<InfoNodo> weighted_tree);

        //BinTree<pair<int, int> > weighted_tree_rec(BinTree<string> mapa_rio, map<string, Ciudad>& lista_ciudades, int unidades_comprar_barco, int unidades_vender_barco);

        //void travel(BinTree<pair<int, int> >, BinTree<string> mapa_rio, map<string, Ciudad>& lista_ciudades, string& last_city);
};
#endif