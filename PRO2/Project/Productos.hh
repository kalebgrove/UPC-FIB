#include "Producto.hh"
#include <list>

/*'Products.hh' is a class that contains a data structure that contains all of the different products that can be used in the program.
It will contain setters; add a product to an inventory; and it will contain getters; list all of the products of an inventory of a city.*/
/*This class is not necessary, since we just need to store the total amount of products that are available to the cities. Therefore we just
need to use an unordered_set to store this information.*/

class Productos {
    private:
        list<Producto> lista_productos = list<Producto> ();
        double peso_total;
        int cantidad_productos;
    
    public:
        //Getters and setters
        
        //Constructores


};