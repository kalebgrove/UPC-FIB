#include "Ciudad.hh"
#include "Producto.hh"
#include "Barco.hh"
#include "BinTree.hh"
#include <vector>

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
#define ERR_MISMA_CIUDAD "error: ciudad repetida"

class Rio {
    private:
        map<string, Ciudad> lista_ciudades; //List of all the cities on the river.
        vector<Producto> lista_productos;   //List of all the products on the river. The indexes of the vector indicate the id of the product.
        BinTree<string> mapa_rio;
        Barco barco;

        BinTree<string> leer_rio_rec();

        void redistribuir_rec(BinTree<string> mapa_rio);

    public:
        //Constructora

        /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un río.
        \pre <em>cierto</em>
        \post El resultado es un rio con lista de ciudades y productos vacias.
        \coste Constante
        */  
        Rio();

        /** @brief Se lee el río. 

        Se ejecuta al llamar la función.
        \pre <em>cierto</em>
        \post El resultado es un rio con los parámetros privados inicializados.
        \coste Lineal: O(n)
        */  
        void leer_rio();


        /** @brief Booleano ciudad. 

        Al llamar la función, devuelve si la ciudad existe en el río o no.
        \pre <em>cierto</em>
        \post El resultado es un booleano indicando la existencia de una ciudad en el río.
        \coste Constante
        */  
        bool existe_ciudad(string id) const;

        /** @brief Booleano producto. 

        Al llamar la función, devuelve si el producto existe en el río o no.
        \pre <em>cierto</em>
        \post El resultado es un rio con lista de ciudades y productos vacias.
        \coste Constante
        */  
        bool existe_producto(int id) const;

        /** @brief Consultora Ciudad. 

        Se devuelve la ciudad con el identificador proporcionado.
        \pre <em>Existe la ciudad</em>
        \post El resultado es una Ciudad.
        \coste Logarítmico: O(log(n))
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
        void leer_inventario(string id_ciudad, int id_producto, int unidades, int unidades_necesarias);

        /** @brief Modificador del Barco. 

        Se modifican los productos del barco.
        \pre <em>cierto</em>
        \post El barco ahora contiene dos productos; uno que vende y otro que compra.
        \coste Constante
        */  
        void modificar_barco(int producto_a_comprar, int producto_a_vender, int unidades_a_comprar, int unidades_a_vender);

        /** @brief Escritura del Barco. 

        Se escribe el inventario del barco.
        \pre <em>el barco tiene inventario</em>
        \post Se escribe en la consola el inventario del barco.
        \coste Logarítmico: log(n)
        */  
        void escribir_barco() const;

        /** @brief Consulta el número de productos en el río. 

        Se escribe el número de productos.
        \pre <em>La lista de productos no es vacia</em>
        \post El resultado es un entero escrito en la consola.
        \coste Constante.
        */  
        void consultar_num() const;

        /** @brief Creadora de productos. 

        Se añade un nuevo producto con características peso y volumen al rio.
        \pre <em>cierto</em>
        \post El resultado es un vector con un producto máss.
        \coste Constante: O(c)
        */  
        void agregar_productos(int peso, int volumen);

        /** @brief Escritura de producto. 

        Se escribe en la consola las características de un producto.
        \pre <em>Existe el producto</em>
        \post Se imprime el peso y volumen de un producto.
        \coste Constante: O(c)
        */  
        void escribir_producto(int id_producto) const;

        /** @brief Escritura de Ciudad. 

        Se escriben los productos de una ciudad en la consola.
        \pre <em>Existe la ciudad</em>
        \post Se imprime los productos que contiene un inventario.
        \coste Lineal: O(n)
        */  
        void escribir_ciudad(string id_ciudad) const;

        /** @brief Se añade un producto.
        
        \pre <em>Existe el producto y la ciudad</em>
        \post La ciudad añade un producto a su inventario
        \coste Logarítmico: log(n)
        */  
        void poner_producto(string id_ciudad, int id_producto, int unidades, int unidades_necesarias);

        /** @brief Contiene el producto la ciudad?. 

        Se devuelve si la ciudad contiene el producto.
        \pre <em>Existe la ciudad y el producto</em>
        \post El resultado es un booleano que nos indica si la ciudad contiene el producto.
        \coste Logarítmico: log(n)
        */  
        bool existe_producto_ciudad(string id_ciudad, int id) const;

        /** @brief Se añade un nuevo producto. 

        La lista de todos los productos se aumenta en 1.
        \pre <em>cierto</em>
        \post Hay un nuevo producto en el río con las características peso y volumen.
        \coste Constante: O(c)
        */  
        void leer_productos(int peso, int volumen);

        /** @brief Se inicializa el barco. 

        El barco se inicializa de nuevo.
        \pre <em>cierto</em>
        \post El barco presenta las características por defecto.
        \coste Lineal: O(n)
        */  
        void iniciar_barco(const int id_prod1, const int id_prod2, const int cantidad1, const int cantidad2);

        /** @brief Se modifican las características de un producto en una ciudad. 

        Las unidades de un producto en una ciudad se modifican.
        \pre <em>Existe la ciudad y el producto</em>
        \post Las cantidades de un producto en una ciudad se reemplazan.
        \coste Logarítmico: log(n)
        */  
        void modificar_producto(string id_ciudad, int id_producto, int unidades, int unidades_necesarias);

        /** @brief Se elimina el producto de una ciudad. 

        La ciudad pierde el producto de su inventario.
        \pre <em>Existe la ciudad y el producto</em>
        \post El producto se ha quitado de la ciudad.
        \coste Logarítmico: log(n)
        */  
        void quitar_producto(string id_ciudad, int id_producto);

        /** @brief Se escriben las características de un producto en una ciudad. 

        Se escribe en la consola las unidades y las unidades necesarias de un producto de una ciudad.
        \pre <em>Existe la ciudad y el producto</em>
        \post Se imprime en la consola las unidades y las unidades necesarias de un producto en la ciudad.
        \coste Lineal: O(n)
        */  
        void caract_producto(string id_ciudad, int id_producto) const;
//---------------------------------------------------------------------------
        /** @brief Contiene el producto la ciudad?. 

        Se devuelve si la ciudad contiene el producto.
        \pre <em>Existe la ciudad y el producto</em>
        \post El resultado es un booleano que nos indica si la ciudad contiene el producto.
        \coste Logarítmico: log(n)
        */  
        void comerciar(string id_ciudad1, string id_ciudad2);

        /** @brief Contiene el producto la ciudad?. 

        Se devuelve si la ciudad contiene el producto.
        \pre <em>Existe la ciudad y el producto</em>
        \post El resultado es un booleano que nos indica si la ciudad contiene el producto.
        \coste Logarítmico: log(n)
        */  
        void redistribuir();

        /** @brief Contiene el producto la ciudad?. 

        Se devuelve si la ciudad contiene el producto.
        \pre <em>Existe la ciudad y el producto</em>
        \post El resultado es un booleano que nos indica si la ciudad contiene el producto.
        \coste Logarítmico: log(n)
        */  
        void hacer_viaje();

        /** @brief Contiene el producto la ciudad?. 

        Se devuelve si la ciudad contiene el producto.
        \pre <em>Existe la ciudad y el producto</em>
        \post El resultado es un booleano que nos indica si la ciudad contiene el producto.
        \coste Logarítmico: log(n)
        */  
        void error_no_ciudad() const;

        /** @brief Contiene el producto la ciudad?. 

        Se devuelve si la ciudad contiene el producto.
        \pre <em>Existe la ciudad y el producto</em>
        \post El resultado es un booleano que nos indica si la ciudad contiene el producto.
        \coste Logarítmico: log(n)
        */  
        void error_no_producto() const;

        /** @brief Contiene el producto la ciudad?. 

        Se devuelve si la ciudad contiene el producto.
        \pre <em>Existe la ciudad y el producto</em>
        \post El resultado es un booleano que nos indica si la ciudad contiene el producto.
        \coste Logarítmico: log(n)
        */  
        void error_no_producto_ciudad() const;

        /** @brief Contiene el producto la ciudad?. 

        Se devuelve si la ciudad contiene el producto.
        \pre <em>Existe la ciudad y el producto</em>
        \post El resultado es un booleano que nos indica si la ciudad contiene el producto.
        \coste Logarítmico: log(n)
        */  
        void error_ciudad_producto() const;

        /** @brief Contiene el producto la ciudad?. 

        Se devuelve si la ciudad contiene el producto.
        \pre <em>Existe la ciudad y el producto</em>
        \post El resultado es un booleano que nos indica si la ciudad contiene el producto.
        \coste Logarítmico: log(n)
        */  
        void error_mismo_producto() const;

        /** @brief Contiene el producto la ciudad?. 

        Se devuelve si la ciudad contiene el producto.
        \pre <em>Existe la ciudad y el producto</em>
        \post El resultado es un booleano que nos indica si la ciudad contiene el producto.
        \coste Logarítmico: log(n)
        */  
        void error_misma_ciudad() const;

        /** @brief Contiene el producto la ciudad?. 

        Se devuelve si la ciudad contiene el producto.
        \pre <em>Existe la ciudad y el producto</em>
        \post El resultado es un booleano que nos indica si la ciudad contiene el producto.
        \coste Logarítmico: log(n)
        */  
        void print_tree();

        /** @brief Contiene el producto la ciudad?. 

        Se devuelve si la ciudad contiene el producto.
        \pre <em>Existe la ciudad y el producto</em>
        \post El resultado es un booleano que nos indica si la ciudad contiene el producto.
        \coste Logarítmico: log(n)
        */  
        void clear_inventory(string id_ciudad);
};