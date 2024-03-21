#include "BinTree.hh"

typedef BinTree<int> BT;

int main() {
  BT t;
  t.setInputFormat(BT::INLINEFORMAT);
  cin >> t;
  t.setOutputFormat(BT::VISUALFORMAT);
  cout << t << endl;
}