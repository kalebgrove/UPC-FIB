/*This is the bottom of the barrel. It directly relates to the 'Products.hh' file.
It doesn't include any other header files because it shouldn't be able to change or modify anything.
It's its own class, since there are getters and setters; change in attributes and consult the information of a product.*/

/** @file Producto.hh
    @brief Especificación de la clase Producto. 
*/


#ifndef _PRODUCTO_HH_
#define _PRODUCTO_HH_

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

class Producto {
    private:
    
        int peso;
        int volumen;

    public:
    
        /** @brief Constructora por defecto.

        Se inicializan los parámetros privados a los valores por defecto.
        \pre <em>cierto</em>
        \post Los parámetros privados del parámetro implícito son inicializados a valores por defecto.
        \coste Constante: O(1)
        */  
        Producto();

        /** @brief Constructora. 

        Se inicializan los parámetros privados del producto.
        \pre <em>cierto</em>
        \post Los parámetros privados están inicializados a aquellos valores pasados como argumentos.
        \coste Constante: O(1)
        */  
        Producto(const int peso, const int volumen);

        /** @brief Consultora de peso.

        Se consulta el peso del parámetro privado.
        \pre <em>cierto</em>
        \post Se devuelve el peso del parámetro implícito.
        \coste Constante: O(1)
        */  
        int consultar_peso() const;

        /** @brief Consultora de volumen.

        Se consulta el volumen del parámetro implícito.
        \pre <em>cierto</em>
        \post Se devuelve el volumen del parámetro implícito.
        \coste Constante: O(1)
        */  
        int consultar_volumen() const;
};

#endif