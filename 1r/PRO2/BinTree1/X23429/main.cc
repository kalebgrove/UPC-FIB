/* Suma dels valors d'un arbre

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "sumOfTree.hh"

typedef BinTree<int> BT;

int main()
{
    string format;
    getline(cin, format);
    BinTree<int> t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    while (cin >> t and not t.empty()) {
    	cout << sumOfTree(t) << endl;
  	}
}
