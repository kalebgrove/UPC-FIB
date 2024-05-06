/*This is the bottom of the barrel. It directly relates to the 'Products.hh' file.
It doesn't include any other header files because it shouldn't be able to change or modify anything.
It's its own class, since there are getters and setters; change in attributes and consult the information of a product.*/
#include <iostream>
using namespace std;

class Producto {
    private:
    //peso y volumen
        string id;
        double peso;
        double volumen;

    public:
    
        Producto() {
            //id?
            peso = 0;
            volumen = 0;
        }
        
        //Anadir productos
        //Consulta de cantidad de productos
};