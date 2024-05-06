#include "Producto.hh"
#include "Productos.hh"
#include <map>

/*Each city has attributes. These cities will be grouped in the 'main.cc' file, such that all of the cities are accessible. There should be a data structure that easily
relates those cities that can commerce between each other, in order to reduce complexity.
In addition, each city will contain an inventory of products, each one with different attributes. These attributes are defined in the 'Product.hh' file.
The city can sell products to another city or to the boat iff these products are in excess (there are more products than what the needs require).
The inventory of the city doesn't have to contain all possible products, just some.*/

struct amount_products {
    int necessary;
    int amount;
};

class Ciudad {
    private:
        string name;
        bool has_inventario;
        map<Producto, amount_products> inventory;

    public:

        //Modificar el inventario de una ciudad
        //Consultar el inventario de una ciudad
        //Consultar un producto del inventario de una ciudad
};