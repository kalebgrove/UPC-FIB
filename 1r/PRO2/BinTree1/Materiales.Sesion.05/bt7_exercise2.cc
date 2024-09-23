#include "BinTree.hh"
#include <list>

typedef BinTree<string> BT;

int bt_heigh(BT t) {

}

int bt_nodes(BT t) {

}

bool bt_search(BT t, int key) {

}

int main() {
	// Read BTree
  BT t;
  t.setInputFormat(BT::INLINEFORMAT);
  cin >> t;

	// Compute height
	cout << "The height of the BinTree is " << bt_heigh(t) << endl;
	// Compute number of nodes
  cout << "The BinTree has " << bt_nodes(t) << "nodes\n";
	// Search for a value
  cout << "The key=10 is in the BinTree? " << bt_search(t,10) << endl;
}
