/* Arrodonir un vector d'estudiants (no main)

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "Estudiant.hh"
#include <vector>

/* Pre: cert */
/* Post: els estudiants de v amb nota passen a tenir la seva nota arrodonida
a la decima mes propera */
 void arrodonir_vector(vector<Estudiant>& v) {
     int n = v.size();
     for(int i = 0; i < n; i++) {
         
         Estudiant *est = &v[i];

         if((*est).te_nota()) {

             double grade = (*est).consultar_nota();

             grade = (int(10.0 * (grade + 0.05))) / 10.0;

             (*est).modificar_nota(grade);
         }
     }
}