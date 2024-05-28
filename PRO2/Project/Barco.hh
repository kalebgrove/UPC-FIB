/** @file Barco.hh
    @brief Especificación de la clase Barco.
*/

#ifndef _BARCO_HH_
#define _BARCO_HH_

#include "Producto.hh"

#ifndef NO_DIAGRAM
#include "Ciudad.hh"
#include "BinTree.hh"
#include <map>
#include <list>
#include <vector>
#endif

/*The boat is the object that allows commerce between two cities. The boat will contain an additional inventory, with its own products, 
such that it is allows to purchase and sell two DIFFERENT products.*/


class Barco {

    public:
    
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

        /** @brief Constructora por defecto.

        Se inicializan a valores por defecto las características del parámetro implícito.
        \pre <em>cierto</em>
        \post Los parámetros privados quedan inicializados a valores por defecto.
        \coste Logarítmico: O(log(n))
        */  
        Barco();

        /** @brief Constructora. 

        Se inicializan los parámetros privados del barco con los valores de los argumentos.
        \pre <em>cierto</em>
        \post Los parámetros privados del barco presentan los valores de los argumentos.
        \coste Constante: O(1)
        */  
        Barco(const int producto_a_comprar, const int producto_a_vender, const int unidades_a_comprar, const int unidades_a_vender);

        /** @brief Se escriben los parámetros privados del barco.

        Se escriben las características del barco en la consola.
        \pre <em>cierto</em>
        \post Se escriben en el canal de salida los parámetros privados.
        \coste Lineal: O(n)
        */  
        void escribir_barco() const;

        /** @brief Se modifica el barco. 

        Se modifican los parámetros privados del parámetro implícito.
        \pre <em>cierto</em>
        \post Los parámetros privados, excepto el vector de ciudades, quedan modificados.
        \coste Constante: O(1)
        */  
        void modificar_barco(int producto_a_comprar, int producto_a_vender, int unidades_a_comprar, int unidades_a_vender);

        /** @brief El barco hace un viaje por la cuenca. 

        El barco realiza la ruta más provechosa e hace comercio con las ciudades.
        \pre <em>Existe la ciudad y el producto</em>
        \post El resultado es un booleano que nos indica si la ciudad contiene el producto.
        \coste Lineal: O(n+k)
        */  
        void hacer_viaje(BinTree<string>& mapa_rio, map<string, Ciudad>& lista_ciudades, vector<Producto>& lista_productos);

        /** @brief Se reinicia el vector de ciudades del barco. 

        Se reinicia el vector que contiene las últimas ciudades con quien ha comerciado el barco.
        \pre <em>cierto</em>
        \post El vector privado queda inicializado al valor por defecto (vacío).
        \coste Logarítmico: O(log(n))
        */  
        void clear_travel();

            private:

        int producto_a_comprar;
        int unidades_a_comprar;

        int producto_a_vender;
        int unidades_a_vender;

        list<string> ultima_ciudad_viaje;

        /** @brief Devuelve un árbol binario que tiene una Struct como nodo. 

        Se crea un árbol binario que contiene Structs como nodos. Esto permite almacenar la información de las rutas. Recorrido pre-orden e in-orden.
        Lo importante es que la ruta se almacena dentro de una lista.
        \pre <em>cierto</em>
        \post Se devuelve un árbol binario además de una lista que contiene las ciudades que forman parte de la ruta.
        \coste Lineal: O(n)
        */  
        BinTree<InfoNodo> travelled_tree_rec(BinTree<string> mapa_rio, map<string, Ciudad>& lista_ciudades, int unidades_comprar_barco, int unidades_vender_barco, list<string>& ruta);

        /** @brief El barco realiza la ruta.

        Se itera sobre la lista que se ha creado en la función recursiva así comerciando entre las ciudades y el barco.
        \pre <em>cierto</em>
        \post Los inventarios y los parámetros privados de las ciudades cambian si comercian con el barco. El vector privado del barco queda modificado: se añade la última ciudad con 
        quien ha comerciado.
        \coste Lineal: O(n)
        */  
        void travel(list<string>& ruta, map<string, Ciudad>& lista_ciudades, vector<Producto>& lista_productos, int u_comprar, int u_vender, string& last_city);

};
#endif