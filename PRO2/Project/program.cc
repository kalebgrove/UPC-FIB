/**
 * @mainpage Ejemplo de diseño modular:  Comercio fluvial.
 
En este ejemplo se construye un programa modular que ofrece un menú de opes para un comercio fluvial. Se introducen las clases <em>Rio</em>, <em>Ciudad</em>, <em>Barco</em> y <em>Producto</em>.

Sólo se documentan elementos públicos. En una próxima sesión se verá un ejemplo
de proyecto completamente documentado, incluyendo los elementos privados.
*/

/** @file pro2_s8.cc
    @brief Programa principal para el ejercicio <em>Comercio Fluvial</em>.
*/

#include "Rio.hh"
#ifndef NO_DIAGRAM
#endif

int main() {
    
    Rio river = Rio();

    //Leemos el número de productos que van a estar disponibles en el río.
    int n;
    cin >> n;

    //En cada iteración añadimos un nuevo producto al vector de productos del río.
    int peso, volumen;
    for(int i = 0; i < n; ++i) {
        cin >> peso >> volumen;
        river.leer_productos(peso, volumen);
    }

    river.leer_rio();

    int id_prod_comprar, id_prod_vender;
    int cant_comprar, cant_vender;
    
    cin >> id_prod_comprar >> cant_comprar;
    cin >> id_prod_vender >> cant_vender;

    river.iniciar_barco(id_prod_comprar, id_prod_vender, cant_comprar, cant_vender);

    string s;
    cin >> s;

    while(s != "fin") {

        if(s == "leer_rio" or s == "lr") {
            cout << '#' << s << endl;

            river.leer_rio();
        }
        else if(s == "leer_inventario" or s == "li") {
            string id_ciudad;
            int n;

            cin >> id_ciudad;
            cin >> n;

            cout << '#' << s << ' ' << id_ciudad << endl;

            bool existe = river.existe_ciudad(id_ciudad);

            if(existe) river.clear_inventory(id_ciudad);
            
            int id_prod;
            int unidades, necesarias;

            for(int i = 0; i < n; ++i) {
                cin >> id_prod >> unidades >> necesarias;

                if(existe) {
                    river.leer_inventario(id_ciudad, id_prod, unidades, necesarias);
                }                
            }

            if(not existe) {
                river.error_no_ciudad();
            }
        }
        else if(s == "leer_inventarios" or s == "ls") {
            string id;
            int n;

            int id_prod, unidades, necesarias;

            cout << '#' << s << endl;

            while(cin >> id and id != "#") {
                cin >> n;

                river.clear_inventory(id);

                for(int i = 0; i < n; ++i) {
                    cin >> id_prod >> unidades >> necesarias;

                    if(river.existe_producto(id_prod)) {
                        river.leer_inventario(id, id_prod, unidades, necesarias);
                    }
                    else {
                        river.error_no_producto();
                    }
                }
            }
        }
        else if(s == "modificar_barco" or s == "mb") {
            
            cout << '#' << s << endl;

            int id_producto1, id_producto2;
            int cantidad_vender, cantidad_comprar;

            cin >> id_producto1 >> cantidad_vender >> id_producto2 >> cantidad_comprar;

            if(river.existe_producto(id_producto1) and river.existe_producto(id_producto2) and id_producto1 != id_producto2) {
                river.modificar_barco(id_producto1, id_producto2, cantidad_vender, cantidad_comprar);
            }
            else if(not river.existe_producto(id_producto1) or not river.existe_producto(id_producto2)) {
                river.error_no_producto();
            }
            else {
                river.error_mismo_producto();
            }
        }
        else if(s == "escribir_barco" or s == "eb") {
            
            cout << '#' << s << endl;

            river.escribir_barco();
        }
        else if(s == "consultar_num" or s == "cn") {
            
            cout << '#' << s << endl;

            river.consultar_num();
        }
        else if(s == "agregar_productos" or s == "ap") {
            
            int n;
            cin >> n;

            cout << '#' << s << ' ' << n << endl;

            int peso, volumen;

            for(int i = 0; i < n; ++i) {
                cin >> peso >> volumen;
                river.agregar_productos(peso, volumen);
            }
        }
        else if(s == "escribir_producto" or s == "ep") {
            
            int id_producto;
            cin >> id_producto;

            cout << '#' << s << ' ' << id_producto << endl;

            if(river.existe_producto(id_producto)) {
                cout << id_producto << ' ';
                river.escribir_producto(id_producto);
            }
            else {
                river.error_no_producto();
            }
        }
        else if(s == "escribir_ciudad" or s == "ec") {
            
            string id_ciudad;
            cin >> id_ciudad;

            cout << '#' << s  << ' ' << id_ciudad << endl;

            if(river.existe_ciudad(id_ciudad)) {
                river.escribir_ciudad(id_ciudad);
            }
            else {
                river.error_no_ciudad();
            }
        }
        else if(s == "poner_prod" or s == "pp") {
            
            string id_ciudad;
            int id_producto;
            int unidades, unidades_quiere;


            cin >> id_ciudad >> id_producto >> unidades >> unidades_quiere;

            cout << '#' << s << ' ' << id_ciudad << ' ' << id_producto << endl;

            if(not river.existe_producto(id_producto)) {
                river.error_no_producto();
            }
            else if(not river.existe_ciudad(id_ciudad)) {
                river.error_no_ciudad();
            }
            else if(river.existe_producto_ciudad(id_ciudad, id_producto)) {
                river.error_ciudad_producto();
            }
            else {                
                river.poner_producto(id_ciudad, id_producto, unidades, unidades_quiere);
            }
        }
        else if(s == "modificar_prod" or s == "mp") {
            string id_ciudad;
            int id_producto;
            int unidades, unidades_necesarias;

            cin >> id_ciudad >> id_producto >> unidades >> unidades_necesarias;
            
            cout << '#' << s << ' ' << id_ciudad << ' ' << id_producto << endl;

            if(not river.existe_producto(id_producto)) river.error_no_producto();
            else if(not river.existe_ciudad(id_ciudad)) river.error_no_ciudad();
            else if(not river.existe_producto_ciudad(id_ciudad, id_producto)) river.error_no_producto_ciudad();
            else {
                river.modificar_producto(id_ciudad, id_producto, unidades, unidades_necesarias);
            }
        }
        else if(s == "quitar_prod" or s == "qp") {
            string id_ciudad;
            int id_producto;

            cin >> id_ciudad >> id_producto;

            cout << '#' << s << ' ' << id_ciudad << ' ' << id_producto << endl;

            if(not river.existe_producto(id_producto)) river.error_no_producto();
            else if(not river.existe_ciudad(id_ciudad)) river.error_no_ciudad();
            else if(not river.existe_producto_ciudad(id_ciudad, id_producto)) river.error_no_producto_ciudad();
            else {
                river.quitar_producto(id_ciudad, id_producto);
            }
        }
        else if(s == "consultar_prod" or s == "cp") {
            string id_ciudad;
            int id_producto;

            cin >> id_ciudad >> id_producto;
            
            cout << '#' << s << ' ' << id_ciudad << ' ' << id_producto << endl;
            
            if(not river.existe_producto(id_producto)) river.error_no_producto();
            else if(not river.existe_ciudad(id_ciudad)) river.error_no_ciudad();
            else if(not river.existe_producto_ciudad(id_ciudad, id_producto)) river.error_no_producto_ciudad();
            else {
                river.caract_producto(id_ciudad, id_producto);
            }
        }
        else if(s == "comerciar" or s == "co") {
            string id_ciudad1, id_ciudad2;
            cin >> id_ciudad1 >> id_ciudad2;
            
            cout << '#' << s << ' ' << id_ciudad1 << ' ' << id_ciudad2 << endl;

            if(not river.existe_ciudad(id_ciudad1) or not river.existe_ciudad(id_ciudad2)) river.error_no_ciudad();
            else if(id_ciudad1 == id_ciudad2) river.error_misma_ciudad();
            else {
                river.comerciar(id_ciudad1, id_ciudad2);
            }
        }
        else if(s == "redistribuir" or s == "re") {
            cout << '#' << s << endl;
            river.redistribuir();
        }
        else if(s == "hacer_viaje" or s == "hv") {
           
            cout << '#' << s << endl;

            river.hacer_viaje();

            //river.print_tree();
        }
        else if(s == "//") {
            string s2;
            getline(cin, s2);
        }

        cin >> s;
    }
}