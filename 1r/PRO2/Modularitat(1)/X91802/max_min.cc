/* Nota màxima i nota mínima d'un vector d'estudiants (no main)

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "Estudiant.hh"
#include <vector>

/* Pre: v no conte repeticions de dni  */
/* Post: si existeix a v algun estudiant amb nota, la primera component del
    resultat es la posicio de l'estudiant de nota maxima de v i la segona
    component es la posicio de l'estudiant de nota minima de v (si hi ha
    empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
    hi ha cap estudiant amb nota, totes dues components valen -1 */

 pair<int,int>  max_min_vest(const vector<Estudiant>& v) {
     double maxi = -1;
     int dni_maxi = 0;
     
     double mini = Estudiant::nota_maxima();
     int dni_mini = 0;

     int pos1 = -1; //Max
     int pos2 = -1; //Min

    for(int i = 0; i < v.size(); i++) {
        
        if(v[i].te_nota()) {
            double grade = v[i].consultar_nota();
            int nie = v[i].consultar_DNI();

            if(grade > maxi) {
                maxi = grade;
                dni_maxi = nie;
                pos1 = i;

            } else if(grade == maxi and nie < dni_maxi) {
                dni_maxi = nie;
                pos1 = i;
            }

            if(grade < mini) {
                mini = grade;
                dni_mini = nie;
                pos2 = i;

            } else if(grade == mini and pos2 == -1) {
                pos2 = i;

            } else if(grade == mini and nie < dni_mini) {
                dni_mini = nie;
                pos2 = i;
            }
        }
    }
    return pair<int, int> (pos1, pos2);
 }