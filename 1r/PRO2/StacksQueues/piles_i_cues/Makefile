OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers
#
G++ = g++-10  #esto solo es necesario en la FIB, ya que su g++ es muy antiguo
#
pert_queue.exe: pert_queue.o queueIOint.o
	$(G++) -o pert_queue.exe pert_queue.o queueIOint.o
#
pert_queue.o: pert_queue.cc queueIOint.hh
	$(G++) -c pert_queue.cc $(OPCIONS) 
#
queueIOint.o: queueIOint.cc queueIOint.hh
	$(G++) -c queueIOint.cc $(OPCIONS) 
#
tar: pert_queue.cc queueIOint.cc queueIOint.hh
	tar cvf sol.tar pert_queue.cc queueIOint.cc queueIOint.hh
#
clean:
	rm -f *.o
	rm -f *.exe
