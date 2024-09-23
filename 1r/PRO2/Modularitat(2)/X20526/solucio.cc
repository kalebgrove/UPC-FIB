/* Mitjana de notes dels estudiants amb nota d'un conjunt

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant& est, bool& b) {
    
    int i = nest-1;
    bool a = false;
    b = false;
    int dni = est.consultar_DNI();
    
    int pos = cerca_dicot(vest, 0, i, dni);
    
    if(dni != vest[pos].consultar_DNI()) {

        while (i >= 0 and not a) {
            if (dni > vest[i].consultar_DNI()) a = true;
            else {
                vest[i+1]=vest[i];
                --i;
            }
        }
    }
    else {
        b = true;
    }

    if(not b){
        vest[i+1] = est;
        ++nest;

        bool has_grade = est.te_nota();

        if(has_grade) {
            double grade = est.consultar_nota();
            suma_notes += grade;
            nest_amb_nota++;
        }
    }    

  // i es la posicio mes avancada amb el DNI mes petit que dni, si n'hi ha;
  // si no, i=-1 
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
    
    int pos = cerca_dicot(vest, 0, nest-1, dni);
    b = false;
    
    if(pos < nest and vest[pos].consultar_DNI() == dni) {

        Estudiant est = vest[pos];
        b = true;

        if(est.te_nota()) {
            double grade = est.consultar_nota();
            suma_notes -= grade;
            nest_amb_nota--;
        }

        vest.erase(vest.begin()+pos);
        nest--;
    }
}