/* Intersecció de llistes ordenades

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>
#include <list>

using namespace std;

void inter(list<int>& uno, const list<int>& dos) {

    list<int>::iterator it1 = uno.begin();
    list<int>::const_iterator it2 = dos.begin();

    while(it1 != uno.end() and it2 != dos.end()) {
        if(*it1 < *it2) {
            list<int>::iterator it1_copy = it1;
            it1++;
            uno.erase(it1_copy);
        } else if(*it1 > *it2) {
            it2++;
        } else {
            it1++;
            it2++;
        }
    }

    if(it2 == dos.end()) {

        while(it1 != uno.end()) {
            list<int>::iterator it1_copy = it1;
            it1++;
            uno.erase(it1_copy);
        }
    }
}
 /* Pre: uno = U */
 /* Post: uno pasa a ser la interseccion de U y dos */