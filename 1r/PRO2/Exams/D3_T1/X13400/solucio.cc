/* Intervals de notes dels estudiants d'un conjunt

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
Fedor Trofimov - https://github.com/fyodormeteor
*/
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
    int i = nest-1;
    int dni = est.consultar_DNI();

    int pos = cerca_dicot(vest, 0, i, dni);

    b = (dni == vest[pos].consultar_DNI());
    
    if(!b) {
        while (i >= pos) {
                vest[i+1]=vest[i];
                --i;
        }
        vest[i+1] = est;
        ++nest;
        
        bool has_grade = est.te_nota();

        if(has_grade) {
            incrementar_interval(est.consultar_nota());
        }
    } 
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
    int pos = cerca_dicot(vest, 0, nest-1, dni);

    b = (pos < nest and dni == vest[pos].consultar_DNI());

    if(b) {

        Estudiant est = vest[pos];
        bool has_grade = est.te_nota();

        if(has_grade) {
            decrementar_interval(est.consultar_nota());
        }

        for(int i = pos; i < nest; i++) {
            vest[i] = vest[i+1];
        }
        nest--;
    }

}

void Cjt_estudiants::incrementar_interval(double x) {
    int grade = x;  //We eliminate the decimals to place it into the interval.

    if(grade == 10) grade--;
    
    intervals[grade]++;
}

void Cjt_estudiants::decrementar_interval(double x) {
    int grade = x;  //We eliminate the decimals to find the correct interval.

    if(grade == 10) grade--;

    intervals[grade]--;
}