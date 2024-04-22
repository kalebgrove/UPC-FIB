/* Intervals de notes dels estudiants d'un conjunt

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
    int i = nest-1;
    int dni = est.consultar_DNI();

    int pos = cerca_dicot(vest, 0, i, dni);
    
    if(dni != vest[pos].consultar_DNI()) {
        while (i >= pos) {
                vest[i+1]=vest[i];
                --i;
        }
        vest[pos] = est;
        ++nest;
        b = false;
    } 
    else {
        b = true;
    }

    bool has_grade = est.te_nota();

    if(has_grade) {
        int grade = est.consultar_nota();
        if(grade == 10) intervals[9]--;
        else intervals[grade]++;
    }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
    int pos = cerca_dicot(vest, 0, nest-1, dni);

    if(dni == vest[pos].consultar_DNI()) {
        for(int i = pos; i < nest-1; i++) {
            vest[i] = vest[i+1];
        }
        nest--;
        b = true;
    }
    else {
        b = false;
    }

    Estudiant est = vest[pos];

    bool has_grade = est.te_nota();

    if(has_grade) {
        int grade = est.consultar_nota();
        if(grade == 10) intervals[9]--;
        else intervals[grade]--;
    }
}

void Cjt_estudiants::incrementar_interval(double x) {
    int grade = x;  //We eliminate the decimals to place it into the interval.

    if(grade == 10) intervals[9]++;
    else intervals[grade]++;
}

void Cjt_estudiants::decrementar_interval(double x) {
    int grade = x;  //We eliminate the decimals to find the correct interval.

    if(grade == 10) intervals[9]--;
    else intervals[grade]--;
}