/* Conjunt d'estudiants amb imax

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "Cjt_estudiants.hh"
#include <algorithm>

Cjt_estudiants::Cjt_estudiants() {
  nest = 0;
  vest = vector<Estudiant>(MAX_NEST);
}
  
void Cjt_estudiants::afegir_estudiant(const Estudiant& est) {
  if (nest >= MAX_NEST) throw PRO2Excepcio("Conjunt ple");
  int i = nest-1;
  bool b = false;
  int dni = est.consultar_DNI();
  while (i >= 0 and not b) {  
    if (dni > vest[i].consultar_DNI()) b = true;
    else {
      vest[i+1]=vest[i];
      --i;
    }
  }
  // i es la posicio mes avancada amb el DNI mes petit que dni, si n'hi ha;
  // si no, i=-1 
  vest[i+1] = est;
  ++nest;

  bool has_grade = est.te_nota();

  if(nest == 1) {
      if(not has_grade) imax = -1;
      else imax = i+1;
  }
  else if(has_grade) {
      if(imax == -1) imax = i+1;
      else if(est.consultar_nota() > estudiant_nota_max().consultar_nota()) imax = i+1;
  }
  //If we insert a student for the first time, and they don't have a grade, we must set imax to -1.
  //If the student does have a grade, then the imax is 0 or i+1;
  //If all the students we've added don't have a grade, but this new one does, therefore imax is i+1.
}

int Cjt_estudiants::cerca_dicot(const vector<Estudiant>& vest, int left, int right, int x) {
/* Pre: vest esta ordenat */
  int i;
  bool found = false;
  while (left <= right and not found) { 
    i = (left + right)/2;
    if (x < vest[i].consultar_DNI()) right = i - 1;
    else if (x > vest[i].consultar_DNI()) left = i + 1; 
    else found = true;
  }
  // i es la posicio, si l'element existeix
  if (found) return i; 
  else return -1;  
}  

void Cjt_estudiants::modificar_estudiant(const Estudiant& est) {
  /* Pre: existeix un estudiant al parametre implicit amb el dni d'est  */
  int x = est.consultar_DNI();
  int i = cerca_dicot(vest,0,nest-1,x);
  vest[i] = est;

  bool has_grade = est.te_nota();

  if(has_grade and imax == -1) imax = i;
  else if(has_grade and est.consultar_nota() > estudiant_nota_max().consultar_nota()) imax = i;
}    
  		
void Cjt_estudiants::modificar_iessim(int i, const Estudiant& est) {
  if (i < 1 or i > nest) throw PRO2Excepcio("Index no valid per a modificar_iessim");
  vest[i-1] = est;

  bool has_grade = est.te_nota();
  
  if(has_grade and imax == -1) imax = i-1;
  else if(has_grade and est.consultar_nota() > estudiant_nota_max().consultar_nota()) imax = i-1;
}
  
int Cjt_estudiants::mida() const {
  return nest;
}
  
int Cjt_estudiants::mida_maxima() {
  return MAX_NEST;
}

bool Cjt_estudiants::existeix_estudiant(int dni) const {
  int i= cerca_dicot(vest,0,nest-1,dni);
  return (i != -1);
}

Estudiant Cjt_estudiants::consultar_estudiant(int dni) const {
  int i=cerca_dicot(vest,0,nest-1,dni);
  return vest[i];
}
 
Estudiant Cjt_estudiants::consultar_iessim(int i) const {
 if (i < 1 or i > nest) throw PRO2Excepcio("Index no valid per a consultar_iessim");
  return vest[i-1];
}

bool comp(const Estudiant& e1, const Estudiant& e2){
  return (e1.consultar_DNI() < e2.consultar_DNI());
}

void Cjt_estudiants::ordenar_cjt_estudiants() {
  sort(vest.begin(),vest.begin()+nest,comp);
}

void Cjt_estudiants::llegir() {
  cin >> nest;
  if (nest > MAX_NEST) throw PRO2Excepcio("El conjunt no pot ser mes gran que la mida maxima");
  for (int i = 0; i < nest; ++i)
    vest[i].llegir();
  ordenar_cjt_estudiants();
}


void Cjt_estudiants::escriure() const {
  for (int i = 0; i < nest; ++i)
    vest[i].escriure();
}

void Cjt_estudiants::esborrar_estudiant(int dni) {
  int pos = cerca_dicot(vest, 0, nest-1, dni);
  vector<Estudiant>::iterator it = vest.begin();

  for(int i = 0; i < pos; ++i) it++;
  vest.erase(it);
  nest--;

  if(pos == imax) recalcular_posicio_imax();
}

Estudiant Cjt_estudiants::estudiant_nota_max( ) const {
  return vest[imax];
}

void Cjt_estudiants::recalcular_posicio_imax() {
  double max_grade = -1;
  imax = -1;

  for(int i = 0; i < nest; i++) {
    Estudiant est = vest[i];
    bool has_grade = est.te_nota();

    if(has_grade and est.consultar_nota() > max_grade) imax = i;
  }
}