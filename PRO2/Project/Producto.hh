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

#ifndef NO_DIAGRAM          // esto hace que el Doxyfile de la sesión no 
#include <iostream>         // incluya estas clases en los diagramas modulares, 
                            // mientras que el compilador de c++ 
#endif                      // sí que las procesa correctamente  

class Producto {
    private:
    
        int id;
        int peso;
        int volumen;

    public:
    
        Producto();

        Producto(int peso, int volumen, int i);
        
        //Anadir productos
        //Consulta de cantidad de productos
};

#endif