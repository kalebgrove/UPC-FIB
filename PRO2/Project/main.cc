/**
 * @mainpage Ejemplo de diseño modular:  Gestión de una lavadora.
 
En este ejemplo se construye un programa modular que ofrece un menú de opes para gestionar una lavadora. Se introducen las clases <em>Lavadora</em>, <em>Cubeta</em> y <em>Prenda</em>.

Sólo se documentan elementos públicos. En una próxima sesión se verá un ejemplo
de proyecto completamente documentado, incluyendo los elementos privados.
*/

/** @file pro2_s8.cc
    @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "Ciudad.hh"
#include "Barco.hh"
#include <set>
#ifndef NO_DIAGRAM
#endif

void leer_productos_totales(map<int, Producto>& lista_productos) {
    int n;              //Número de productos.
    cin >> n;
    //Lista de todos los productos disponibles.
    int peso, volumen;

    for(int i = 0; i < n; ++i) {
        cin >> peso >> volumen;

        //We create a product with the constructor from the class 'Producto'
        Producto product = Producto(peso, volumen, i);

        //We append the product to the map.
        lista_productos[i+1] = product;
    }
}

void leer_productos_barco() {

}

int main() {
    //Se comienza leyendo cuantos productos diferentes hay, y se leen sus pesos y volúmenes.

    Producto producto = Producto();
    Ciudad ciudad = Ciudad();

    map<int, Producto> lista_productos;
    leer_productos_totales(lista_productos);

    //Ahora leemos la estructura de la cuenca:

    //TO DO
    set<string> lista_ciudades_nombres;     //Contains the id of each city: this list allows us to see if the list is in the river itself.
    map<string, Ciudad> lista_ciudades;     //Relates the name of each city with the city itself (optimization)

    //We will need a map that will unite the cities.

    //Call function and add the cities to the list.

    //Finalmente leemos los datos del barco; qué producto quiere comprar y qué producto quiere vender + cuantas unidades.
    //No hay situaciones erróneas en estos datos iniciales.
    int id_comprar;
    int cantidad_a_comprar;
    int id_vender;
    int cantidad_a_vender;
    cin >> id_comprar >> cantidad_a_comprar >> id_vender >> cantidad_a_vender;     
    //We may need to change this input since we need to know when the BT ends as an input and may have to read identificador to make sure it isn't a name of a city.

    Barco barco = Barco(id_comprar, id_vender, cantidad_a_comprar, cantidad_a_vender);

    string s;
    cin >> s;

    while(s != "fin") {

        if(s == "leer_rio" or s == "lr") {
            //Se reinicia la cuenca
        }
        else if(s == "leer_inventario" or s == "li") {
            //Se lee el inventario de una ciudad.
            string id;      //id of the city
            cin >> id;

            if(lista_ciudades_nombres.count(id) < 1) {
                cout << "error: no existe la ciudad\n";
            }
            else {
                int n;
                cin >> n;   //We read the amount of product that will be added to the inventory.

                Ciudad city = lista_ciudades[id];
                int id_producto, unidades, unidades_necesarias;

                for(int i = 0; i < n; ++i) {
                    cin >> id_producto >> unidades >> unidades_necesarias;

                    Producto product = lista_productos[id_producto];        //We fetch the product from the map, that will contain the weight and volume.

                    city.add_inventory(id_producto, unidades, unidades_necesarias, product);
                }
            }
        }
        else if(s == "leer_inventarios" or s == "ls") {

        }
        else if(s == "modificar_barco" or s == "mb") {

        }
        else if(s == "escribir_barco" or s == "eb") {

        }
        else if(s == "consultar_num" or s == "cn") {

        }
        else if(s == "agregar_productos" or s == "ap") {

        }
        else if(s == "escribir_producto" or s == "ep") {

        }
        else if(s == "escribir_ciudad" or s == "ec") {

        }
        else if(s == "poner_prod" or s == "pp") {

        }
        else if(s == "modificar_producto" or s == "mp") {

        }
        else if(s == "quitar_prod" or s == "qp") {

        }
        else if(s == "consultar_producto" or s == "cp") {
            
        }
        else if(s == "comerciar" or s == "co") {

        }
        else if(s == "redistribuir" or s == "re") {

        }
        else if(s == "hacer_viaje" or s == "hv") {

        }
        else if(s == "fin") {
            
        }
    }
}

/*1. leer_rio o lr. Se leerán los identificadores de las ciudades indicando la estructura
de la cuenca. No se escribe nada.
2. leer_inventario o li. Se leerá el identificador de una ciudad. Si la ciudad no existe
se escribirá un mensaje de error. Si la ciudad existe, se leerá un número que indica la cantidad de elementos del inventario y para cada uno de ellos se leerá el
identificador del producto, cuantas unidades tiene la ciudad y cuantas necesita.
3. leer_inventarios o ls. Se leerán los inventarios de ciudades del río. No necesariamente todas las ciudades tendrán inventario.
4. modificar_barco o mb. Se leerá el identificador del producto que se quiere comprar
y la cantidad, y el identificador del producto que se quiere vender y la cantidad.
Si algún producto no existe, se escribirá un mensaje de error. Si los dos productos
son el mismo, se escribirá un mensaje de error. Se garantiza que ambas cantidades
serán no negativas y al menos una de ellas será estrictamente positiva.
5. escribir_barco o eb. Se escriben los cuatro valores mencionados en la anterior operación y los viajes realizados, en orden cronológico. Para cada viaje solo se ha de
escribir la última ciudad visitada de la ruta escogida.
6. consultar_num o cn. Escribe cuantos productos diferentes hay.
7. agregar_productos o ap. Se lee el número de productos nuevos, mayor que 0. Sus
identificadores serán correlativos a partir del último producto existente. Se leerán
sus pesos y volúmenes respectivos.
3 ©PRO2, CS-UPC
8. escribir_producto o ep. Se lee el identificador de un producto. Si no existe el producto se escribe un mensaje de error. En caso contrario se escribe el peso y volumen
del producto.
9. escribir_ciudad o ec. Se leerá el identificador de una ciudad. Si la ciudad no existe
se escribirá un mensaje de error. Si la ciudad existe, se escribirá su inventario, y el
peso y el volumen total de los productos almacenados.
10. poner_prod o pp. Se leerá el identificador de una ciudad, de un producto y las
unidades que tiene y que quiere. Si el producto no existe escribe un mensaje de
error. Si la ciudad no existe, escribe un mensaje de error. Si el producto ya está en
el inventario de la ciudad, escribe un mensaje de error. Si no hay errores, los datos
de ese producto se añaden a la ciudad, modificándose el peso y el volumen total si
hace falta. Se escribe el peso y el volumen total.
11. modificar_prod o mp. Se leerá el identificador de una ciudad, de un producto y las
unidades que tienen y que quiere. Si el producto no existe escribe un mensaje de
error. Si la ciudad no existe, escribe un mensaje de error. Si el producto no está en
el inventario de la ciudad, escribe un mensaje de error. Si no hay errores, los datos
de ese producto sustituyen a los que había en la ciudad, modificándose el peso y
el volumen total si hace falta. Se escribe el peso y el volumen total. El número de
unidades necesitadas se puede modificar, pero siempre ha de ser mayor que 0.
12. quitar_prod o qp. Se leerá el identificador de una ciudad y de un producto. Si
el producto no existe escribe un mensaje de error. Si la ciudad no existe, escribe
un mensaje de error. Si el producto no está en el inventario de la ciudad, escribe
un mensaje de error. Si no hay errores, se quitan los datos de este producto en la
ciudad, modificándose el peso y el volumen total si hace falta. Se escribe el peso y
el volumen total.
13. consultar_prod o cp. Se leerá el identificador de una ciudad y de un producto. Si
el producto no existe escribe un mensaje de error. Si la ciudad no existe, escribe un
mensaje de error. Si el producto no está en el inventario de la ciudad, escribe un
mensaje de error. Si no hay errores, se escribe cuantas unidades de ese producto
tiene y quiere la ciudad.
14. comerciar o co. Se leerán los identificadores de dos ciudades. Si no existen alguna
de las dos (o las dos), se escribe un mensaje de error. Si las dos ciudades existen se
intercambian los productos que le sobren a una y necesite la otra.
15. redistribuir o re. No se leen datos. La ciudad de la desembocadura comercia con su
ciudad río arriba a mano derecha y luego con la ciudad río arriba a mano izquierda,
y así sucesivamente.
16. hacer_viaje o hv. El barco busca la ruta a partir de la desembocadura que le permita comprar y vender el mayor número posible de productos. En caso que haya
más de una ruta que lo cumpla, se queda con la más corta, y en caso de que tengan la misma longitud, se queda con la que viene río arriba a mano derecha. Una
©PRO2, CS-UPC 4
vez encontrada la ruta, se hace el viaje y se compran y venden los productos a lo
largo de la ruta, modificándose los inventarios de las ciudades. Se escribe el total
de unidades de productos compradas y vendidas por el barco.
17. fin. Acaba la ejecución.*/