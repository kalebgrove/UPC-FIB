OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.exe: program.o Rio.o Ciudad.o Producto.o Barco.o
	g++ -o program.exe program.o Rio.o Ciudad.o Producto.o Barco.o

Producto.o: Producto.cc
	g++ -c Producto.cc $(OPCIONS)

Ciudad.o: Ciudad.cc
	g++ -c Ciudad.cc $(OPCIONS)

Barco.o: Barco.cc
	g++ -c Barco.cc $(OPCIONS)

Rio.o: Rio.cc
	g++ -c Rio.cc $(OPCIONS)

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

clean:
	rm -f *.o
	rm -f *.exe
	rm -f *.tar

tar: Barco.cc Barco.hh Ciudad.cc Ciudad.hh Makefile Producto.cc Producto.hh program.cc Rio.cc Rio.hh
	tar -cvf practica.tar Barco.cc Barco.hh Ciudad.cc Ciudad.hh Makefile Producto.cc Producto.hh program.cc Rio.cc Rio.hh