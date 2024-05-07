/** @file Barco.hh
    @brief Especificación de la clase Barco 
*/

#ifndef _BARCO_HH_
#define _BARCO_HH_

#ifndef NO_DIAGRAM          // esto hace que el Doxyfile de la sesión no incluya estas clases en los diagramas modulares, 
#include <iostream>         // mientras que el compilador de c++
#include "Producto.hh"
#include <map>
#endif                      // sí que las procesa correctamente  #include "Producto.hh"

/*The boat is the object that allows commerce between two cities. The boat will contain an additional inventory, with its own products, 
such that it is allows to purchase and sell two DIFFERENT products.*/

class Barco {
    private:

        //Inventario de productos del barco: hay dos estructuras de datos; una para los productos que se quieren comprar
        //y otra para los productos que se quieren vender.
        int producto_a_comprar; //Identificador
        int unidades_a_comprar;

        int producto_a_vender;  //Identificador
        int unidades_a_vender;

        int num_viajes;

        string ciudad_anterior;
        //inventario: lista de productos que tiene a disposicion el barco;
        //Numero de viajes

    public:
        Barco();

        Barco(int producto_a_comprar, int producto_a_vender, int unidades_a_comprar, int unidades_a_vender);

        
        //Modificar los datos de un barco
        //Escribir los datos del barco
};
#endif