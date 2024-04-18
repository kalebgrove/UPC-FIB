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

        set_students.afegir_estudiant(est);
    }

    for(int i = 0; i < m; ++i) {
        Estudiant est2;
        est2.llegir();

        int dni = est2.consultar_DNI();
        double grade = est2.consultar_nota();

        Estudiant original = set_students.consultar_estudiant(dni);
        double original_grade = original.consultar_nota();

        if(original_grade < grade) {
            original.modificar_nota(grade);
            set_students.modificar_estudiant(original);
        }
    }
}