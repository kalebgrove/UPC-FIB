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
#include "Prenda.hh"
#include "Lavadora.hh"
#include "Cubeta.hh"
#ifndef NO_DIAGRAM // explicado en Prenda.hh
#include "readbool.hh"
#endif

/** @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/
int main ()
{
    Lavadora lav = Lavadora();
    Cubeta cub = Cubeta();
    int op;
    cin >> op;

    while(op != -8) {
        if (op == -1) {
            int pmax;
            cin >> pmax;

            bool color = readbool();

            lav.inicializar(pmax, color);
        } // inicializar lavadora (datos: peso máximo y color)
        else if (op == -2) {
            int weight;
            cin >> weight;

            bool color = readbool();

            Prenda p = Prenda(weight, color);

            lav.anadir_prenda(p);
        } // añadir una prenda a la lavadora (datos: peso  y color de la prenda)

        else if (op == -3) {
            int weight;
            cin >> weight;

            bool color = readbool();

            Prenda p = Prenda(weight, color);

            cub.anadir_prenda(p);
        } // añadir una prenda a la cubeta (datos: peso  y color de la prenda)

        else if (op == -4) {
            cub.completar_lavadora(lav);
        } // completar la lavadora

        else if (op == -5) {
            lav.lavado();
        } // realizar un lavado

        else if (op == -6) {
            cub.escribir();
            cout << endl;
        } // escribir el contenido de la cubeta

        else if (op == -7) {
            cout << "   Lavadora: " << endl;
            lav.escribir();
            cout << endl;
        } // escribir el contenido de la lavadora

        cin >> op;
    }
}
