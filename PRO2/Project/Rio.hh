#include "Ciudad.hh"
#include "Producto.hh"
#include "Barco.hh"
#include <vector>

using namespace std;

/** @class Rio
    @brief Representa el río con todos sus elementos.

    Puede contener ciudades y productos. El barco es una entidad separada que no depende de la presencia de la cuenca.
*/

/*Define errors*/

#define ERR_NO_CIUDAD "error: no existe la ciudad"
#define ERR_NO_PRODUCTO "error: no existe el producto"
#define ERR_NO_PRODUCTO_CIUDAD "error: la ciudad no tiene el producto"
#define ERR_CIUDAD_TIENE_PRODUCTO "error: la ciudad ya tiene el producto"
#define ERR_MISMO_PRODUCTO_COMPRAVENDA "error: no se puede comprar y vender el mismo producto"

class Rio {
    private:
        map<string, Ciudad> lista_ciudades; //List of all the cities on the river.
        vector<Producto> lista_productos;   //List of all the products on the river. The indexes of the vector indicate the id of the product.

    public:
        //Constructora

        /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un río.
        \pre <em>cierto</em>
        \post El resultado es un rio con lista de ciudades y productos vacias.
        \coste Constante
        */  
        Rio();

        /** @brief Booleano ciudad. 

        Al llamar la función, devuelve si la ciudad existe en el río o no.
        \pre <em>cierto</em>
        \post El resultado es un booleano indicando la existencia de una ciudad en el río.
        \coste Constante
        */  
        bool existe_ciudad(string id) const;

        /** @brief Booleano producto. 

        Al llamar la función, devuelce si el producto existe en el río o no.
        \pre <em>cierto</em>
        \post El resultado es un rio con lista de ciudades y productos vacias.
        \coste Constante
        */  
        bool existe_producto(int id) const;

        /** @brief Consultora Ciudad. 

        Se devuelve la ciudad con el identificador proporcionado.
        \pre <em>Existe la ciudad</em>
        \post El resultado es una Ciudad.
        \coste Logarítmico: log(n)
        */  
        Ciudad consultar_ciudad(string id) const;

        /** @brief Consultora Producto. 

        Se devuelve el producto con el identificador proporcionado.
        \pre <em>Existe el producto</em>
        \post El resultado es un Producto.
        \coste Logarítmico: O(log(n))
        */  
        Producto consultar_producto(int id) const;

        /** @brief Leer Inventario de una Ciudad. 

        Se escribe el inventario de una ciudad.
        \pre <em>Existe la ciudad</em>
        \post Se escribe en la consola el inventario de una ciudad.
        \coste Lineal: O(n)
        */  
        void leer_inventario(Ciudad& city, Producto& producto, int id_producto, int unidades, int unidades_necesarias);

        /** @brief Modificador del Barco. 

        Se modifican los productos del barco.
        \pre <em>cierto</em>
        \post El barco ahora contiene dos productos; uno que vende y otro que compra.
        \coste Constante
        */  
        void modificar_barco(Barco& barco, int producto_a_comprar, int producto_a_vender, double unidades_a_comprar, double unidades_a_vender);

        /** @brief Escritura del Barco. 

        Se escribe el inventario del barco.
        \pre <em>el barco tiene inventario</em>
        \post Se escribe en la consola el inventario del barco.
        \coste Logarítmico: log(n)
        */  
        void escribir_barco(Barco& barco) const;

        /** @brief Consulta el número de productos en el río. 

        Se escribe el número de productos.
        \pre <em>La lista de productos no es vacia</em>
        \post El resultado es un entero escrito en la consola.
        \coste Constante.
        */  
        void consultar_num() const;

//--------
        /** @brief Consultora Ciudad. 

        Se devuelve la ciudad con el identificador proporcionado.
        \pre <em>Existe la ciudad</em>
        \post El resultado es una Ciudad.
        \coste Logarítmico: log(n)
        */  
        void agregar_productos(double peso, double volumen);

        /** @brief Consultora Ciudad. 

        Se devuelve la ciudad con el identificador proporcionado.
        \pre <em>Existe la ciudad</em>
        \post El resultado es una Ciudad.
        \coste Logarítmico: log(n)
        */  
        void escribir_producto(int id_producto) const;

        /** @brief Consultora Ciudad. 

        Se devuelve la ciudad con el identificador proporcionado.
        \pre <em>Existe la ciudad</em>
        \post El resultado es una Ciudad.
        \coste Logarítmico: log(n)
        */  
        void escribir_ciudad(string id_ciudad) const;

        /** @brief Consultora Ciudad. 

        Se devuelve la ciudad con el identificador proporcionado.
        \pre <em>Existe la ciudad</em>
        \post El resultado es una Ciudad.
        \coste Logarítmico: log(n)
        */  
        void poner_producto(string id_ciudad, int id_producto, int unidades, int unidades_necesarias);

        /** @brief Consultora Ciudad. 

        Se devuelve la ciudad con el identificador proporcionado.
        \pre <em>Existe la ciudad</em>
        \post El resultado es una Ciudad.
        \coste Logarítmico: log(n)
        */  
        bool existe_producto_ciudad(string id_ciudad, int id) const;

        void modificar_producto(string id_ciudad, int id_producto, int unidades, int unidades_necesarias);

        void quitar_producto(string id_ciudad, int id_producto);

        void caract_producto(string id_ciudad, int id_producto) const;

        void error_no_ciudad() const;

        void error_no_producto() const;

        void error_no_producto_ciudad() const;

        void error_ciudad_producto() const;

        void error_ciudad_tiene_producto() const;

        void error_mismo_producto() const;
};