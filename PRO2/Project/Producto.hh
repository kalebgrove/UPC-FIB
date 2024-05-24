/*This is the bottom of the barrel. It directly relates to the 'Products.hh' file.
It doesn't include any other header files because it shouldn't be able to change or modify anything.
It's its own class, since there are getters and setters; change in attributes and consult the information of a product.*/
#include <iostream>
using namespace std;

/** @file Prenda.hh
    @brief Especificación de la clase Prenda 
*/


#ifndef _PRODUCTO_HH_
#define _PRODUCTO_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#endif

class Producto {
    private:
    
        int peso;
        int volumen;

    public:
    
        Producto();

        Producto(const int peso, const int volumen);

        int consultar_peso() const;

        int consultar_volumen() const;
};

#endif