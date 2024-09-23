/* Simplificació d'un vector d'estudiants agrupats

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "Estudiant.hh"

using namespace std;

int main() {
    int n;
    cin >> n;

    int dni = 0;
    int temp_dni;
    double grade = 0;
    double temp_grade;

    for(int i = 0; i < n; ++i) {

        cin >> temp_dni >> temp_grade;

        //Base case: we read the first input
        if(i == 0) {
            dni = temp_dni;
            if(temp_grade > 10 or temp_grade < 0) grade = -1;
            else grade = temp_grade;

        } else {
            if(dni == temp_dni) {

                if(temp_grade > grade and temp_grade <= 10 and temp_grade >= 0) {
                    grade = temp_grade;
                }

            } else {
                cout << dni << ' ';
                if(grade == -1) cout << "NP" << endl;
                else cout << grade << endl;
                
                dni = temp_dni;
                grade = temp_grade;
            }
        }
    }
    cout << dni << ' ';
    if(grade > 10) cout << "NP" << endl;
    else cout << grade << endl;
}