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
    
        double peso;
        double volumen;

    public:
    
        Producto();

        Producto(double peso, double volumen);

        double consultar_peso() const;

        double consultar_volumen() const;
        
        //Anadir productos
        //Consulta de cantidad de productos
};

#endif