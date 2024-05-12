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
    int unidades_necesarias;
    int unidades;
};

class Ciudad {
    private:
        string name;
        map<int, Producto> inventario;               //It relates the id of the product to the product itself (optimization)
        map<int, amount_products> InfoProductos;     //It relates the id of the product with the struct with info about needs.

        double peso_total;
        double volumen_total;

    public:
        Ciudad();

        Ciudad(string name);

        void anadir_inventario(Producto& producto, int id_prod, int unidades, int unidades_necesarias);

        void escribir_ciudad() const;

        void poner_producto(Producto& producto, int id_producto, int unidades, int unidades_necesarias);

        bool contiene_producto(int id) const;

        void modificar_producto(int id_producto, int unidades, int unidades_necesarias);

        void quitar_producto(int id_producto);

        void caract_producto(int id_producto) const;

        int mida_inventario() const;

        int consultar_iesimo_producto(int i) const;

        int cantidad_necesaria(int id_producto) const;

        void reduccion(int id_producto, int cantidad);

        void adquisicion(int id_producto, int cantidad);

        Producto consultar_producto(int id_producto);

        void recalculate_weight();
};

#endif