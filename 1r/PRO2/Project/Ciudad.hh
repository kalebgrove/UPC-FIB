/*Each city has attributes. These cities will be grouped in the 'main.cc' file, such that all of the cities are accessible. There should be a data structure that easily
relates those cities that can commerce between each other, in order to reduce complexity.
In addition, each city will contain an inventory of products, each one with different attributes. These attributes are defined in the 'Product.hh' file.
The city can sell products to another city or to the boat iff these products are in excess (there are more products than what the needs require).
The inventory of the city doesn't have to contain all possible products, just some.*/

/** @file Ciudad.hh
    @brief Especificación de la clase Ciudad.
*/


#ifndef _CIUDAD_HH_
#define _CIUDAD_HH_

#include "Producto.hh"

#ifndef NO_DIAGRAM          // esto hace que el Doxyfile de la sesión no 
#include <map>
#include <set>              // incluya estas clases en los diagramas modulares, 
                            // mientras que el compilador de c++
#include <vector>
#endif                      // sí que las procesa correctamente  

//Struct that contains the amount of products needed and the total amount of products.

/** @class Ciudad
    @brief Especificación de la Ciudad que contiene un inventario con productos, en addición al peso y volumen total.
*/

class Ciudad {
    public:
    
        /** @brief Constructora por defecto. 

        Se inicializan los parámetros privados.
        \pre <em>cierto</em>
        \post Los parámetros privados de la clase se inicializan.
        \coste Constante: O(1)
        */  
        Ciudad();

        /** @brief Escritura de la ciudad. 

        Se escriben en el canal de salida los parámetros privados de la ciudad.
        \pre <em>Existe la ciudad</em>
        \post Se escribe en la consola los parámetros privados de la ciudad.
        \coste Lineal: O(n), donde n es el número de productos del inventario.
        */  
        void escribir_ciudad() const;

        /** @brief Getter de la cantidad de productos del inventario. 

        Se devuelve el tamaño del inventario.
        \pre <em>cierto</em>
        \post La función devuelve un integer que indica el tamaño del inventario.
        \coste Constante: O(1)
        */  
        int tam_inventario() const;

        /** @brief Contiene el producto la ciudad? 

        Se devuelve un booleano que indica la presencia de un producto en el inventario de la ciudad.
        \pre <em>cierto</em>
        \post La función devuelve un booleano que indica si el producto está en el inventario de la ciudad.
        \coste Logarítmico: O(log(n)), donde n es el número de productos del inventario de la ciudad.
        */  
        bool contiene_producto(int id) const;

        /** @brief Se devuelve el exceso de un producto que tiene la ciudad.

        El exceso determina si la ciudad quiere comprar o vender el producto: si el exceso es positivo, la ciudad tiene más unidades que las necesarias, y puede vender
        el producto. En cambio, si el exceso es negativo, el parámetro implícito contiene menos unidades que las necesarias: necesita comprar el producto.
        \pre <em>cierto</em>
        \post Se devuelve la diferencia entre las unidades y las unidades necesarias de un producto que pertenece al inventario del parámetro implícito.
        \coste Logarítmico: O(log(n)), donde n es el número de productos del inventario de la ciudad.
        */  
        int exceso(const int id_producto) const;

        /** @brief Se escriben las unidades y unidades necesarias de un producto.

        Se escribe en el canal de salida las características de un producto.
        \pre <em>Existe el producto</em>
        \post Se escribe en la consola las características de un producto.
        \coste Logarítmico: O(log(n)), donde n es el número de productos del inventario de la ciudad.
        */  
        void caract_producto(const int id_producto) const;

        /** @brief Se añade un producto al inventario de la ciudad. 

        Se añade un producto al inventario del parámetro implícito.
        \pre <em>cierto</em>
        \post El inventario de la ciudad adquiere un nuevo producto, con las características pasadas por copia.
        \coste Logarítmico: O(log(n)), donde n es el número de productos del inventario de la ciudad.
        */  
        void anadir_inventario(Producto& producto, const int id_prod, const int unidades, const int unidades_necesarias);

        /** @brief Se añade un producto al inventario y se escribe el peso y el volumen total del parámetro implícito. 

        \pre <em>cierto</em>
        \post El inventario de la ciudad aquiere un producto y se escribe en el canal de salida el peso y volumen total.
        \coste Logarítmico: O(log(n)), donde n es el número de productos del inventario de la ciudad.
        */  
        void poner_producto(Producto& producto, const int id_producto, const int unidades, const int unidades_necesarias);

        /** @brief Se modifican las características de un producto.

        Las unidades y las unidades necesarias de un producto en el inventario se modifican.
        \pre <em>cierto</em>
        \post Las características de un producto cambian, y así el peso y el volumen total del parámetro implícito.
        \coste Logarítmico: O(log(n)), donde n es el número de productos del inventario de la ciudad.
        */  
        void modificar_producto(const int id_producto, const int unidades, const int unidades_necesarias, Producto& product);

        /** @brief Se elimina un producto del inventario.

        El inventario del parámetro implícito queda reducido, además del peso y volumen total.
        \pre <em>cierto</em>
        \post Se reduce el inventario de la ciudad y el peso y volumen total.
        \coste Logarítmico: O(log(n)), donde n es el número de productos del inventario de la ciudad.
        */  
        void quitar_producto(const int id_producto, Producto& product);

        /** @brief La cantidad de un producto decrementa una cierta cantidad. 

        Se ha comerciado con el barco o con otra ciudad, tal que el parámetro implícito ha vendido una cantidad de producto (exceso).
        \pre <em>cierto</em>
        \post La cantidad de un producto del inventario del parámetro implícito se reduce; el peso y el volumen total también.
        \coste Logarítmico: O(log(n)), donde n es el número de productos del inventario de la ciudad.
        */  
        void reduccion(const int id_producto, const int cantidad, Producto& product);

        /** @brief La cantidad de un producto aumenta una cierta cantidad. 

        Se ha comerciado con el barco o con otra ciudad, tal que el parámetro implícito ha comprado una cantidad de producto (exceso).
        \pre <em>cierto</em>
        \post La cantidad de un producto del inventario del parámetro implícito se aumenta; el peso y el volumen total también.
        \coste Logarítmico: O(log(n)), donde n es el número de productos del inventario de la ciudad.
        */  
        void adquisicion(const int id_producto, const int cantidad, Producto& product);

        /** @brief Comercio entre dos ciudades. 

        Se comercia entre dos ciudades determinadas.
        \pre <em>cierto</em>
        \post Si las ciudades tienen productos en común, entonces hay un intercambio.
        \coste Lineal: O(k+m), donde k es el número de productos del inventario del parámetro implícito, y m es el número de productos del inventario de city2.
        Dentro de cada iteración, si hay un intercambio de productos, se llama la función 'exceso' de coste logarítmico y 'reduccio' y 'adquisicion', todos tres de coste logarítmico.
        */  
        void comerciar(Ciudad& city2, vector<Producto>& lista_productos);

        /** @brief Se reinicia el inventario del parámetro implícito. 

        El inventario de la ciudad se inicializa al valor por defecto (vacío).
        \pre <em>cierto</em>
        \post Tanto el inventario como el peso y volumen total quedan inicializados a los valores por defecto.
        \coste Lineal: O(n), donde n es el número de productos del inventario del parámetro implícito.
        */  
        void clear_inventory();
    
    private:

        /** @struct amount_products
            @brief Especificación del Struct amount_products que contiene la información sobre cada producto del inventario de la ciudad.
        */

        struct amount_products {
            int unidades_necesarias;
            int unidades;
        };

        map<int, amount_products> InfoProductos;     //It relates the id of the product with the struct with info about needs.

        int peso_total;
        int volumen_total;

};

#endif