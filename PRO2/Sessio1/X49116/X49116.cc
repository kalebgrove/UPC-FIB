/* Mínim i màxim d'un vector (sense main)

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/

#include <iostream>
#include <vector>
#include "vectorIOint.hh"
using namespace std;
 
struct parint {int prim, seg;};

/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
    el segundo componente del resultado es el valor minimo de v */

parint max_min1(const vector<int>& v)
{
    parint x;
    x.prim = v[0]; //Maximum
    x.seg = v[0];   //Minimum

    int n = int(v.size());

    for(int i = 0; i < n; ++i) {
        if(v[i] > x.prim) x.prim = v[i];
        if(v[i] < x.seg) x.seg = v[i];
    }

    return x;
}

/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
el segundo componente del resultado es el valor minimo de v */
pair<int,int> max_min2(const vector<int>& v)
{
    pair <int,int> x;
    x.first = v[0]; //Maximum
    x.second = v[0];   //Minimum

    int n = int(v.size());

    for(int i = 0; i < n; ++i) {
        if(v[i] > x.first) x.first = v[i];
        if(v[i] < x.second) x.second = v[i];
    }

    return x;
}

/* Pre: v.size()>0 */
/* Post: x es el valor maximo de v;  y es el valor minimo de v */
void max_min3(const vector<int>& v, int& x, int& y)
{
    x = v[0];
    y = v[0];

    int n = int(v.size());

    for(int i = 0; i < n; ++i) {
        if(v[i] > x) x = v[i];
        if(v[i] < y) y = v[i];
    }
}