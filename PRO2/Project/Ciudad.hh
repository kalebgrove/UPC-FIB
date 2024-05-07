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
#endif                      // sí que las procesa correctamente  

//Struct that contains the amount of products needed and the total amount of products.
struct amount_products {
    int necessary;
    int amount;
};

class Ciudad {
    private:
        string name;
        bool has_inventory;
        map<int, Producto> inventory;               //It relates the id of the product to the product itself (optimization)
        map<int, amount_products> InfoProducts;     //It relates the id of the product with the struct with info about needs.

    public:
        Ciudad();

        Ciudad(string name);

        void add_inventory(int id_producto, int unidades, int unidades_necesarias, Producto product);
        
};

#endif