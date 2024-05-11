/**
 * @mainpage Ejemplo de diseño modular:  Gestión de una lavadora.
 
En este ejemplo se construye un programa modular que ofrece un menú de opes para gestionar una lavadora. Se introducen las clases <em>Lavadora</em>, <em>Cubeta</em> y <em>Prenda</em>.

Sólo se documentan elementos públicos. En una próxima sesión se verá un ejemplo
de proyecto completamente documentado, incluyendo los elementos privados.
*/

/** @file pro2_s8.cc
    @brief Programa principal para el ejercicio <em>Comercio Fluvial</em>.
*/

#include "Rio.hh"
#include <set>
#ifndef NO_DIAGRAM
#endif

int main() {
    
    Rio river = Rio();
    Barco barco = Barco();

    string s;
    cin >> s;
    while(s != "fin") {

        if(s == "leer_rio" or s == "lr") {
            //Se reinicia la cuenca
        }
        else if(s == "leer_inventario" or s == "li") {
            string id;
            int n;

            cin >> id >> n;

            bool existe = river.existe_ciudad(id);

            int id_prod;
            int unidades, necesarias;

            for(int i = 0; i < n; ++i) {
                cin >> id_prod >> unidades >> necesarias;

                if(existe) {
                    Ciudad city = river.consultar_ciudad(id);
                    Producto producto = river.consultar_producto(id_prod);

                    river.leer_inventario(city, producto, id_prod, unidades, necesarias);
                }                
            }
        }
        else if(s == "leer_inventarios" or s == "ls") {
            string id;
            int n;
            cin >> id >> n;

            int id_prod, unidades, necesarias;

            while(id != "#") {

                for(int i = 0; i < n; ++i) {
                    cin >> id_prod >> unidades >> necesarias;

                    Ciudad city = river.consultar_ciudad(id);
                    Producto producto = river.consultar_producto(id_prod);

                    river.leer_inventario(city, producto, id_prod, unidades, necesarias);
                }

            }
        }
        else if(s == "modificar_barco" or s == "mb") {
            int id_producto1, id_producto2;
            double cantidad_vender, cantidad_comprar;

            cin >> id_producto1 >> cantidad_vender >> id_producto2 >> cantidad_comprar;

            if(river.existe_producto(id_producto1) and river.existe_producto(id_producto2) and id_producto1 != id_producto2) {
                river.modificar_barco(barco, id_producto1, id_producto2, cantidad_vender, cantidad_comprar);
            }
        }
        else if(s == "escribir_barco" or s == "eb") {
            river.escribir_barco(barco);
        }
        else if(s == "consultar_num" or s == "cn") {
            river.consultar_num();
        }
        else if(s == "agregar_productos" or s == "ap") {
            int n;
            cin >> n;

            double peso, volumen;

            for(int i = 0; i < n; ++i) {
                cin >> peso >> volumen;
                river.agregar_productos(peso, volumen);
            }
        }
        else if(s == "escribir_producto" or s == "ep") {
            int id_producto;
            cin >> id_producto;


            if(river.existe_producto(id_producto)) {
                river.escribir_producto(id_producto);
            }
        }
        else if(s == "escribir_ciudad" or s == "ec") {
            string id_ciudad;
            cin >> id_ciudad;

            if(river.existe_ciudad(id_ciudad)) {
                river.escribir_ciudad(id_ciudad);
            }
        }
        else if(s == "poner_prod" or s == "pp") {
            string id_ciudad;
            int id_producto;
            int unidades, unidades_quiere;

            cin >> id_ciudad >> id_producto >> unidades >> unidades_quiere;

            if(not river.existe_ciudad(id_ciudad)) {
                river.error_no_ciudad();
            }
            else if(not river.existe_producto(id_producto)) {
                river.error_no_producto();
            }
            else {
                Ciudad city = river.consultar_ciudad(id_ciudad);
                
                if(not river.existe_producto_ciudad(id_ciudad, id_producto)) {
                    river.error_no_producto_ciudad();
                }
                else {
                    river.poner_producto(id_ciudad, id_producto, unidades, unidades_quiere);
                }
            }
        }
        else if(s == "modificar_producto" or s == "mp") {
            string id_ciudad;
            int id_producto;
            int unidades, unidades_necesarias;

            cin >> id_ciudad >> id_producto >> unidades >> unidades_necesarias;

            if(not river.existe_ciudad(id_ciudad)) river.error_no_ciudad();
            else if(not river.existe_producto(id_producto)) river.error_no_producto();
            else if(not river.existe_producto_ciudad(id_ciudad, id_producto)) river.error_ciudad_producto();
            else {
                river.modificar_producto(id_ciudad, id_producto, unidades, unidades_necesarias);
            }
        }
        else if(s == "quitar_prod" or s == "qp") {
            string id_ciudad;
            int id_producto;

            cin >> id_ciudad >> id_producto;

            if(not river.existe_ciudad(id_ciudad)) river.error_no_ciudad();
            else if(not river.existe_producto(id_producto)) river.error_no_producto();
            else if(not river.existe_producto_ciudad(id_ciudad, id_producto)) river.error_ciudad_tiene_producto();
            else {
                river.quitar_producto(id_ciudad, id_producto);
            }
        }
        else if(s == "consultar_producto" or s == "cp") {
            string id_ciudad;
            int id_producto;

            cin >> id_ciudad >> id_producto;

            if(not river.existe_producto(id_producto)) river.error_no_producto();
            else if(not river.existe_ciudad(id_ciudad)) river.error_no_ciudad();
            else if(not river.existe_producto_ciudad(id_ciudad, id_producto)) river.error_ciudad_tiene_producto();
            else {
                river.caract_producto(id_ciudad, id_producto);
            }
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