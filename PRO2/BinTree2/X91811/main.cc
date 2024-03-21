/* Suma dels valors d'un arbre a profunditat parell

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "sumAtDepthEven.hh"

typedef BinTree<int> BT;

int main()
{
    string format;
    getline(cin, format);
    BT t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    while (cin >> t and not t.empty()) {
      bool even = false;
      cout << sumAtDepthEven(t) << endl;
  }
}
