#ifndef CONJ_EST_HPP
#define CONJ_EST_HPP

#include "Estudiant.hh"
#include <vector>

class Cjt_estudiants { // nomes tenen Pre/Post les noves operacions

private:

  // Representa un conjunt ordenat per DNI d'estudiants.
  
  // Es poden consultar i modificar els seus elements de tipus
  // Estudiant donat un DNI o per posició en l'ordre.

  vector<Estudiant> vest;
  int nest;
  static const int MAX_NEST = 10001;
  int imax; // nou atribut

  void ordenar_cjt_estudiants ();
  /* Pre: cert */
  /* Post: els elements del paràmetre implícit estan ordenats
     creixentment pels seus DNI */

  static int cerca_dicot(const vector<Estudiant> &vest, 
			 int left, int right, int x);
  /* Pre: vest[left..right] està ordenat creixentment per DNI,
     0<=left, right<vest.size() */
  /* Post: si a vest[left..right] hi ha un element amb DNI = x, el
     resultat és una posició que el conté; si no, el resultat és -1 */

  void recalcular_posicio_imax();
  /* Pre: cert */
  /* Post: el camp imax conté la posició de l'element del paràmetre
     implícit amb la nota més gran */

public:

  //Constructores

  Cjt_estudiants();

  //Modificadores

  void afegir_estudiant(const Estudiant& est);

  void modificar_estudiant(const Estudiant& est);

  void modificar_iessim(int i, const Estudiant& est);

  void esborrar_estudiant(int dni);
  /* Pre: existeix un estudiant al paràmetre implícit amb DNI = dni */
  /* Post: el paràmetre implícit conté els mateixos estudiants que
     l'original menys l'estudiant amb DNI = dni */

  // Consultores
	
  int mida() const;

  static int mida_maxima();

  bool existeix_estudiant(int dni) const;

  Estudiant consultar_estudiant(int dni) const;

  Estudiant consultar_iessim(int i) const;

  Estudiant estudiant_nota_max() const;
  /* Pre: el paràmetre implícit conté almenys un estudiant amb nota */
  /* Post: el resultat és l'estudiant del paràmetre implícit amb nota
     màxima; si en té més d'un, és el de DNI més petit */ 
 		
  // Lectura i escriptura
	
  void llegir();

  void escriure() const;

};
#endif
