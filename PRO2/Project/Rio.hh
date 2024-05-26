#include "Ciudad.hh"
#include "Producto.hh"
#include "Barco.hh"
#include "BinTree.hh"
#include <vector>

/** @file Rio.hh
    @brief Especificación de la clase Rio. 
*/

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

        /** @brief Función auxiliar de leer el río. 

        Es una función auxiliar recursiva que permite crear un árbol binario que contiene los identificadores de las ciudades como el valor del nodo.
        \pre <em>cierto</em>
        \post El resultado es un árbol binario con los identificadores de las ciudades como nodos.
        \coste Lineal: O(n*log(n))
        */  
        BinTree<string> leer_rio_rec();

        /** @brief Función auxiliar de redistribuir. 

        Es una función auxiliar que permite recorrer el árbol binario y hacer la redistribución.
        \pre <em>cierto</em>
        \post Se llama la función comerciar para cada par de ciudades.
        \coste Lineal: O(n)
        */  
        void redistribuir_rec(BinTree<string> mapa_rio);

    public:

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
        bool existe_ciudad(const string id) const;

        /** @brief Booleano producto. 

        Al llamar la función, devuelve si el producto existe en el río o no.
        \pre <em>cierto</em>
        \post El resultado es un rio con lista de ciudades y productos vacias.
        \coste Constante
        */  
        bool existe_producto(const int id) const;

        /** @brief Leer Inventario de una Ciudad. 

        Se escribe el inventario de una ciudad.
        \pre <em>Existe la ciudad</em>
        \post Se escribe en la consola el inventario de una ciudad.
        \coste Lineal: O(n)
        */  
        void leer_inventario(const string id_ciudad, const int id_producto, const int unidades, const int unidades_necesarias);

        /** @brief Modificador del Barco. 

        Se modifican los productos del barco.
        \pre <em>cierto</em>
        \post El barco ahora contiene dos productos; uno que vende y otro que compra.
        \coste Constante
        */  
        void modificar_barco(const int producto_a_comprar, const int producto_a_vender, const int unidades_a_comprar, const int unidades_a_vender);

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
        void agregar_productos(const int peso, const int volumen);

        /** @brief Escritura de producto. 

        Se escribe en la consola las características de un producto.
        \pre <em>Existe el producto</em>
        \post Se imprime el peso y volumen de un producto.
        \coste Constante: O(c)
        */  
        void escribir_producto(const int id_producto) const;

        /** @brief Escritura de Ciudad. 

        Se escriben los productos de una ciudad en la consola.
        \pre <em>Existe la ciudad</em>
        \post Se imprime los productos que contiene un inventario.
        \coste Lineal: O(n)
        */  
        void escribir_ciudad(const string id_ciudad) const;

        /** @brief Se añade un producto.
        
        \pre <em>Existe el producto y la ciudad</em>
        \post La ciudad añade un producto a su inventario
        \coste Logarítmico: log(n)
        */  
        void poner_producto(const string id_ciudad, const int id_producto, const int unidades, const int unidades_necesarias);

        /** @brief Contiene el producto la ciudad?

        Se devuelve si la ciudad contiene el producto.
        \pre <em>Existe la ciudad y el producto</em>
        \post El resultado es un booleano que nos indica si la ciudad contiene el producto.
        \coste Logarítmico: log(n)
        */  
        bool existe_producto_ciudad(const string id_ciudad, const int id) const;

        /** @brief Se añade un nuevo producto. 

        La lista de todos los productos se aumenta en 1.
        \pre <em>cierto</em>
        \post Hay un nuevo producto en el río con las características peso y volumen.
        \coste Constante: O(c)
        */  
        void leer_productos(const int peso, const int volumen);

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
        void modificar_producto(const string id_ciudad, const int id_producto, const int unidades, const int unidades_necesarias);

        /** @brief Se elimina el producto de una ciudad. 

        La ciudad pierde el producto de su inventario.
        \pre <em>Existe la ciudad y el producto</em>
        \post El producto se ha quitado de la ciudad.
        \coste Logarítmico: log(n)
        */  
        void quitar_producto(const string id_ciudad, const int id_producto);

        /** @brief Se escriben las características de un producto en una ciudad. 

        Se escribe en la consola las unidades y las unidades necesarias de un producto de una ciudad.
        \pre <em>Existe la ciudad y el producto</em>
        \post Se imprime en la consola las unidades y las unidades necesarias de un producto en la ciudad.
        \coste Lineal: O(n)
        */  
        void caract_producto(const string id_ciudad, const int id_producto) const;

        /** @brief Comercio entre dos ciudades. 

        Se comercia entre dos ciudades determinadas.
        \pre <em>Existen ambas ciudades</em>
        \post Si las ciudades tienen productos en común, entonces se comercia.
        \coste Lineal: O(k+m)
        */  
        void comerciar(const string id_ciudad1, const string id_ciudad2);

        /** @brief Redistribuir.

        Se redistribuye entre las ciudades del río.
        \pre <em>cierto</em>
        \post La ciudad comercia con la ciudad de la derecha y luego con el de la izquierda río arriba.
        \coste Cuadrático: O(n*(k+m))
        */  
        void redistribuir();

        /** @brief El barco hace un viaje por la cuenca. 

        El barco realiza la ruta más provechosa e hace comercio con las ciudades.
        \pre <em>Existe la ciudad y el producto</em>
        \post El resultado es un booleano que nos indica si la ciudad contiene el producto.
        \coste Lineal: O(n+k)
        */  
        void hacer_viaje();

        /** @brief La ciudad no existe en el río.

        Se intenta acceder a una ciudad que no existe.
        \pre <em>No existe la ciudad</em>
        \post Se escribe en la consola un mensaje de error.
        \coste Constante> O(1)
        */  
        void error_no_ciudad() const;

        /** @brief El producto no existe en el río. 

        Se intenta acceder a un producto que no existe.
        \pre <em>No existe el producto</em>
        \post Se escribe en la consola un mensaje de error.
        \coste Constante: O(1)
        */  
        void error_no_producto() const;

        /** @brief La ciudad no contiene el producto. 

        Se intenta modificar un producto de una ciudad.
        \pre <em>La ciudad no contiene el producto</em>
        \post Se escribe en la consola un mensaje de error.
        \coste Constante: O(1)
        */  
        void error_no_producto_ciudad() const;

        /** @brief La ciudad contiene el producto. 

        Se intenta añadir a una ciudad un producto que ya contiene.
        \pre <em>Existe la ciudad y el producto</em>
        \post Se escribe en la consola un mensaje de error.
        \coste Constante: O(1)
        */  
        void error_ciudad_producto() const;

        /** @brief Dos productos son iguales. 

        Se intenta modificar el barco con dos productos que son iguales.
        \pre <em>Existe el producto</em>
        \post Se escribe en la consola un mensaje de error.
        \coste Constante: O(1)
        */  
        void error_mismo_producto() const;

        /** @brief Dos ciudades son iguales 

        Se intenta comerciar entre dos ciudades que son la misma.
        \pre <em>Existe la ciudad</em>
        \post Se escribe en la consola un mensaje de error.
        \coste Constante: O(1)
        */  
        void error_misma_ciudad() const;

        /** @brief Se reinicia el inventario de una ciudad. 

        Se vuelve a declarar el inventario por defecto de una ciudad.
        \pre <em>La ciudad existe</em>
        \post El inventario de la ciudad especificada está vacia.
        \coste Logarítmico: O(log(n))
        */  
        void clear_inventory(const string id_ciudad);
};