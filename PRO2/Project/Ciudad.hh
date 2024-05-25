/*Each city has attributes. These cities will be grouped in the 'main.cc' file, such that all of the cities are accessible. There should be a data structure that easily
relates those cities that can commerce between each other, in order to reduce complexity.
In addition, each city will contain an inventory of products, each one with different attributes. These attributes are defined in the 'Product.hh' file.
The city can sell products to another city or to the boat iff these products are in excess (there are more products than what the needs require).
The inventory of the city doesn't have to contain all possible products, just some.*/

/** @file Ciudad.hh
    @brief Especificación de la clase Ciudad 
*/


#ifndef _CIUDAD_HH_
#define _CIUDAD_HH_

#ifndef NO_DIAGRAM          // esto hace que el Doxyfile de la sesión no 
#include "Producto.hh"
#include <map>
#include <set>              // incluya estas clases en los diagramas modulares, 
#include <iostream>         // mientras que el compilador de c++
#include <vector>
#endif                      // sí que las procesa correctamente  

//Struct that contains the amount of products needed and the total amount of products.
struct amount_products {
    int unidades_necesarias;
    int unidades;
};

class Ciudad {
    private:
        map<int, amount_products> InfoProductos;     //It relates the id of the product with the struct with info about needs.

        int peso_total;
        int volumen_total;

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
        \coste Lineal> O(n)
        */  
        void escribir_ciudad() const;

        /** @brief Getter de la cantidad de productos del inventario. 

        Se devuelve el tamaño del inventario.
        \pre <em>cierto</em>
        \post La función devuelve un integer que indica el tamaño del inventario.
        \coste Lineal: O(k+m)
        */  
        int tamaño_inventario() const;

        /** @brief Contiene el producto la ciudad? 

        Se devuelve un booleano que indica la presencia de un producto en el inventario de la ciudad.
        \pre <em>cierto</em>
        \post La función devuelve un booleano que indica si el producto está en el inventario de la ciudad.
        \coste Logarítmico: O(log(n))
        */  
        bool contiene_producto(int id) const;

        /** @brief Comercio entre dos ciudades. 

        Se comercia entre dos ciudades determinadas.
        \pre <em>Existen ambas ciudades</em>
        \post Si las ciudades tienen productos en común, entonces se comercia.
        \coste Lineal: O(k+m)
        */  
        int exceso(const int id_producto) const;

        /** @brief Comercio entre dos ciudades. 

        Se comercia entre dos ciudades determinadas.
        \pre <em>Existen ambas ciudades</em>
        \post Si las ciudades tienen productos en común, entonces se comercia.
        \coste Lineal: O(k+m)
        */  
        void caract_producto(const int id_producto) const;

        /** @brief Comercio entre dos ciudades. 

        Se comercia entre dos ciudades determinadas.
        \pre <em>Existen ambas ciudades</em>
        \post Si las ciudades tienen productos en común, entonces se comercia.
        \coste Lineal: O(k+m)
        */  
        void anadir_inventario(Producto& producto, const int id_prod, const int unidades, const int unidades_necesarias);

        /** @brief Comercio entre dos ciudades. 

        Se comercia entre dos ciudades determinadas.
        \pre <em>Existen ambas ciudades</em>
        \post Si las ciudades tienen productos en común, entonces se comercia.
        \coste Lineal: O(k+m)
        */  
        void poner_producto(Producto& producto, const int id_producto, const int unidades, const int unidades_necesarias);

        /** @brief Comercio entre dos ciudades. 

        Se comercia entre dos ciudades determinadas.
        \pre <em>Existen ambas ciudades</em>
        \post Si las ciudades tienen productos en común, entonces se comercia.
        \coste Lineal: O(k+m)
        */  
        void modificar_producto(const int id_producto, const int unidades, const int unidades_necesarias, Producto& product);

        /** @brief Comercio entre dos ciudades. 

        Se comercia entre dos ciudades determinadas.
        \pre <em>Existen ambas ciudades</em>
        \post Si las ciudades tienen productos en común, entonces se comercia.
        \coste Lineal: O(k+m)
        */  
        void quitar_producto(const int id_producto, Producto& product);

        /** @brief Comercio entre dos ciudades. 

        Se comercia entre dos ciudades determinadas.
        \pre <em>Existen ambas ciudades</em>
        \post Si las ciudades tienen productos en común, entonces se comercia.
        \coste Lineal: O(k+m)
        */  
        void reduccion(const int id_producto, const int cantidad, Producto& product);

        /** @brief Comercio entre dos ciudades. 

        Se comercia entre dos ciudades determinadas.
        \pre <em>Existen ambas ciudades</em>
        \post Si las ciudades tienen productos en común, entonces se comercia.
        \coste Lineal: O(k+m)
        */  
        void adquisicion(const int id_producto, const int cantidad, Producto& product);

        /** @brief Comercio entre dos ciudades. 

        Se comercia entre dos ciudades determinadas.
        \pre <em>Existen ambas ciudades</em>
        \post Si las ciudades tienen productos en común, entonces se comercia.
        \coste Lineal: O(k+m)
        */  
        void comerciar(Ciudad& city2, vector<Producto>& lista_productos);

        /** @brief Comercio entre dos ciudades. 

        Se comercia entre dos ciudades determinadas.
        \pre <em>Existen ambas ciudades</em>
        \post Si las ciudades tienen productos en común, entonces se comercia.
        \coste Lineal: O(k+m)
        */  
        void clear_inventory();
};

#endif