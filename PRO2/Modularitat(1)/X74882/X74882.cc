/* Actualitzar un conjunt d'estudiants

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"

using namespace std;

int main() {
    Cjt_estudiants set1;
    set1.llegir();

    Cjt_estudiants set2;
    set2.llegir();

    int n = set1.mida();

    for(int i = 1; i <= n; i++) {
        Estudiant est1 = set1.consultar_iessim(i);
        Estudiant est2 = set2.consultar_iessim(i);

        int dni1 = est1.consultar_DNI();
        int dni2 = est2.consultar_DNI();

        if(est2.te_nota()) {

            if(dni1 == dni2) {

                if(est1.te_nota() and est1.consultar_nota() < est2.consultar_nota()){
                    set1.modificar_iessim(i, est2);
                }
                else if(not est1.te_nota()) {
                    set1.modificar_iessim(i, est2);
                }
            }
            
        }
    }
    set1.escriure();
}