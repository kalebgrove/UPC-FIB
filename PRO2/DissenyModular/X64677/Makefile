OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers
#
program.exe: Lavadora.o program.o Cubeta.o Prenda.o
	g++ -o program.exe Lavadora.o program.o Cubeta.o Prenda.o

Lavadora.o: Lavadora.cc
	g++ -c Lavadora.cc $(OPCIONS)

Cubeta.o: Cubeta.cc
	g++ -c Cubeta.cc $(OPCIONS)

Prenda.o: Prenda.cc
	g++ -c Prenda.cc $(OPCIONS)

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

clean:
	rm -f *.o
	rm -f *.exe