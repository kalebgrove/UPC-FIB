#include "Estudiant.hh"
#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant& est, bool& b) {
    
    int i = nest-1;
    bool a = false;
    b = false;
    int dni = est.consultar_DNI();
    
    while (i >= 0 and not a) {
        if (dni > vest[i].consultar_DNI()) a = true;
        else if(dni == vest[i].consultar_DNI()) {
            a = true;
            b = true;
        }
        else {
            vest[i+1]=vest[i];
            --i;
        }
    }

    if(not b){
        vest[i+1] = est;
        ++nest;

        bool has_grade = est.te_nota();

        if(has_grade) {
            suma_notes += est.consultar_nota();
            nest_amb_nota++;
        }
    }    

  // i es la posicio mes avancada amb el DNI mes petit que dni, si n'hi ha;
  // si no, i=-1 
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
    
    int pos = cerca_dicot(vest, 0, nest-1, dni);
    b = false;
    
    if(vest[pos].consultar_DNI() == dni) {

        b = true;
        vector<Estudiant>::iterator it = vest.begin();
        it += pos;

        if(it->te_nota()) {
            suma_notes -= it->consultar_nota();
            nest_amb_nota--;
        }

        vest.erase(it);
        nest--;
    }
}