/* Actualitzar un conjunt d'estudiants

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"

using namespace std;

int main() {
    int m; //Number of students
    cin >> m;

    auto set_students = Cjt_estudiants();

    for(int i = 0; i < m; ++i) {
        Estudiant est;
        est.llegir();
        
        if(not est.te_nota()) est.afegir_nota(0.00);

        set_students.afegir_estudiant(est);
    }

    int n;
    cin >> n;

    auto set_students2 = Cjt_estudiants();

    for(int i = 0; i < n; ++i) {
        Estudiant est2;
        est2.llegir();

        if(not est2.te_nota()) est2.afegir_nota(0.00);

        set_students2.afegir_estudiant(est2);
    }

    auto set_students3 = Cjt_estudiants();

    //int i = 1, j = 1;
    //cout << n << ' ' << m << endl;
    int i = 1;
    int j = 1;

    while(i <= m and j <= n) {
        Estudiant est1 = set_students.consultar_iessim(i);
        Estudiant est2 = set_students2.consultar_iessim(j);

        int dni1 = est1.consultar_DNI();
        int dni2 = est2.consultar_DNI();

        double grade1 = est1.consultar_nota();
        double grade2 = est2.consultar_nota();

        if(dni1 != dni2) {
            if(dni1 < dni2) {
                set_students3.afegir_estudiant(est1);
                i++;
            } else {
                set_students3.afegir_estudiant(est2);
                j++;
            }
        }
        else if (dni1 == dni2){
            if(grade1 < grade2) {
                est1.modificar_nota(grade2);
                set_students3.afegir_estudiant(est1);
            } else {
                set_students3.afegir_estudiant(est1);
            }
            i++;
            j++;
        }
    }

    if(j != n) {
        while (j <= n){
            Estudiant est2 = set_students2.consultar_iessim(j);
            set_students3.afegir_estudiant(est2);
            j++;
        }
    }
    set_students = set_students3;
    set_students.escriure();
}