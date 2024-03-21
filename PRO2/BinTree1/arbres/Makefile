OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers
G++ = g++-10  #esto solo es necesario en la FIB, ya que su g++ es muy antiguo
#
# INCLUSIONS se puede definir aqui:
INCLUSIONS = $(HOME)/assig/pro2/inclusions
#
mida_arbre.exe: mida_arbre.o BinTreeIOint.o
	g++ -o mida_arbre.exe mida_arbre.o BinTreeIOint.o
#
mida_arbre.o: mida_arbre.cc BinTreeIOint.hh
	g++ -c mida_arbre.cc -I$(INCLUSIONS) $(OPCIONS) 
#
BinTreeIOint.o: BinTreeIOint.cc BinTreeIOint.hh
	g++ -c BinTreeIOint.cc -I$(INCLUSIONS) $(OPCIONS) 
#
tar: mida_arbre.cc BinTreeIOint.cc BinTreeIOint.hh
	tar cvf sol.tar mida_arbre.cc BinTreeIOint.cc BinTreeIOint.hh
#
clean:
	rm -f *.o
	rm -f *.exe
