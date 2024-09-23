#include "Cjt_estudiants.hh"
#include <algorithm>

Cjt_estudiants::Cjt_estudiants()
{
  nest = 0;
  vest = vector<Estudiant>(MAX_NEST);
  nest_amb_nota = 0;
  suma_notes = 0;
}

int Cjt_estudiants::cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x)
{
  int i; 
  bool found=false;
  while (left <= right and not found) { 
    i = (left + right)/2;
    if (x < vest[i].consultar_DNI()) right = i-1; 
    else if (x > vest[i].consultar_DNI()) left = i + 1; 
    else found = true;
  } 
  if (found) return i;
  else return left;
}  

int Cjt_estudiants::mida() const
{
  return nest;
}

int Cjt_estudiants::mida_maxima() {
  return MAX_NEST;
}

double Cjt_estudiants::mitjana_estudiants_amb_nota() const
{
  if (nest_amb_nota == 0)
    return -1;
  else
    return suma_notes/nest_amb_nota;
}

void Cjt_estudiants::ordenar_cjt_estudiants (){
  sort(vest.begin(),vest.begin()+nest,Estudiant::comp);
}

void Cjt_estudiants::llegir(){
  //cout << "Escriu la mida del conjunt i els elements" << endl;
  cin >> nest;
  nest_amb_nota = 0;
  suma_notes = 0;
  for (int i=0; i<nest; ++i) {
    vest[i].llegir();
    if (vest[i].te_nota()) {
      ++nest_amb_nota; 
      suma_notes += vest[i].consultar_nota();
    }
  }
  ordenar_cjt_estudiants();
}

void Cjt_estudiants::escriure() const{
  for (int i=0; i<nest; ++i)
    vest[i].escriure();
//cout << suma_notes << " " << nest_amb_nota << endl;
}
