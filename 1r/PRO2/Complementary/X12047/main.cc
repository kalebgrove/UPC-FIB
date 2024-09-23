/* Nombre de fulles d'un arbre

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "numberOfLeaves.hh"

typedef BinTree<int> BT;

int main()
{
    string format;
    getline(cin, format);
    BT t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    while (cin >> t and not t.empty()) {
    	cout << numberOfLeaves(t) << endl;
  	}
}
