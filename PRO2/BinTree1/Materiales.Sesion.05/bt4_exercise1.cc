#include "BinTree.hh"

typedef BinTree<string> BT;

int main()
{
  BT t1 = BT();              // t1 = () = 
  BT t2 = BT("a", t1, t1);   // t2 = a((),()) = a(,) = a
  BT t3 = BT("b", t2, t1);   // t3 = b(a,)
  BT t4 = BT("c", t2, t3);   // t4 = c(a,b(a,))
  BT t5 = BT("d", t4, t3);   // t5 = d(c(a,b(a,)),b(a,))

	t5.setOutputFormat(BT::INLINEFORMAT);
  cout << t5 << endl; // Exercise a: Output?

  BT t10 = BT(t5.value(), BT("a", BT(), BT()), t5.right());
	t10.setOutputFormat(BT::VISUALFORMAT);
  cout << t10 << endl; // Exercise b: Output?
}

