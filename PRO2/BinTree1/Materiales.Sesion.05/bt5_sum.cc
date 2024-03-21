#include "BinTree.hh"

typedef BinTree<int> BT;

// PRE: 
// POST:
int sumTree(BT t) {
	if (t.empty()) return 0;
  int sum = t.value();
	sum += sumTree(t.left());
	sum += sumTree(t.right());
	return sum;
}

// PRE: 
// POST:
int sumTreeDepthEven(BT t) {
	if (t.empty()) return 0;
  int sum = t.value();
  if (not t.left().empty()) {
    sum += sumTreeDepthEven(t.left().left());
    sum += sumTreeDepthEven(t.left().right());
  }
  if (not t.right().empty()) {
    sum += sumTreeDepthEven(t.right().left());
    sum += sumTreeDepthEven(t.right().right());
  }
	return sum;
}

int main() {
  // Constructors
  BT t1;            // t1 es un árbol vacı́o
  BT t2(8, t1, t1); // t2 =    8(,) = 8 (arbol con 8 en la raı́z
                    //                   y dos subárboles vacı́os)
  BT t3(3, t2, t1); // t3 =   3(8,)
  BT t4(2, t1, t1); // t4 =              2
  BT t5(1, t1, t4); // t5 =           1(,2)
  BT t6(7, t5, t2); // t6 =         7(1(,2),8)
  BT t7(5, t3, t6); // t7 = 5(3(8,),7(1(,2),8))

	// Print
  t7.setOutputFormat(BT::VISUALFORMAT);
  cout << t7 << endl;
	// Sum the elements of a tree
	cout << sumTree(t7) << endl;
	// Sum the elements (at an even level) of a tree
	cout << sumTreeDepthEven(t7) << endl;
}