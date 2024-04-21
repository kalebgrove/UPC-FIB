/* Actualitzar un conjunt d'estudiants

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int m; //Number of students
    cin >> m;

    Cjt_estudiants set_students = Cjt_estudiants();
    set<int> position;

    for(int i = 0; i < m; ++i) {
    cout << i << endl;
        Estudiant est;
        est.llegir();
        int dni = est.consultar_DNI();

        if(not est.te_nota()) est.afegir_nota(0);

        set_students.afegir_estudiant(est);
        position.insert(dni);
    }

    cin >> m;

    for(int i = 0; i < m; ++i) {
        int dni;
        double grade;
        cin >> dni >> grade;

        if(position.count(dni) != 0) {
            set<int>::iterator it = position.find(dni);
            int pos = distance(position.begin(), it);
            cout << pos << endl;

            if(0 <= grade and grade <= 10 and set_students.consultar_iessim(pos).consultar_nota() < grade) {
                Estudiant est2 = Estudiant(dni);
                est2.afegir_nota(grade);
                set_students.modificar_iessim(pos, est2);
            }
        }
        else {
            Estudiant est2 = Estudiant(dni);
            est2.afegir_nota(grade);
            set_students.afegir_estudiant(est2);
        }
        
    }

    set_students.escriure();
}