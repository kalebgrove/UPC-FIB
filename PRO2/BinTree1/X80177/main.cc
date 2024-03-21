/* Arbre revessat

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "reverseTree.hh"

typedef BinTree<int> BT;

int main()
{
    string format;
    getline(cin, format);
    BT t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    while (cin >> t and not t.empty()) {
        t = reverseTree(t);
        t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
        cout << t << endl;
  	}
}
