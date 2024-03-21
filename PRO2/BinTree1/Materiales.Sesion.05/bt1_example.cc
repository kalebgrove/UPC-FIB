#include "BinTree.hh"

typedef BinTree<int> BT;

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

  // Unmutable
	//t8.value() = 11; // COMPILATION ERROR
  //t8.left() = BT(t3, t4); // COMPILATION ERROR
  //t8.right() = BT(t1, t10); // COMPILATION ERROR

  // Accessors Methods
  int x = t7.value();                // x = 5
  BT t8 = t7.left();                 // t8 = 3(8,)
  BT t9 = t7.right();                // t9 = 7(1(,2),8)
  BT t10 = t9.left();                // t10 = 1(,2)
  BT t11 = t7.right().left();        // t11 = 1(,2)
  int y = t7.right().left().value(); // y = 1
  int z = t11.value();               // z = 1
  // Is empty?
	cout << t1.empty() << endl; // output: 1 (true)
  cout << t2.empty() << endl; // output: 0 (false)
  // Traverse Tree
  cout << t7.right().right().value() << endl;
}