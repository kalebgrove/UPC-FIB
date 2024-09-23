/* Búsqueda lineal en un vector (sin main)

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/

#include <iostream>
#include <vector>
#include "vectorIOint.hh"

using namespace std;

/* Buscar  */    
int busqueda_lin(const vector<int>& v, int x)
/* Pre: cierto */
/* Post: el resultado indica si x está en v */
{
  int tam = v.size();
  int i = 0;
  bool b = false;
  while (i < tam and not b) {
    if (v[i]==x) b=true; 
    else ++i;
  }
  return i;
}
