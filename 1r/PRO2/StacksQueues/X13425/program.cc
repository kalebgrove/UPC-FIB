/* Distribució justa de cues

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "CuaIOParInt.hh"

using namespace std;

int main() {
    queue<ParInt> q1;
    queue<ParInt> q2;

    queue<ParInt> c;

    llegirCuaParInt(c);

    int t_q1 = 0, t_q2 = 0;

    while(not c.empty()) {
        if(t_q1 <= t_q2) {
            q1.push(c.front());
            t_q1 += c.front().segon();
        } else {
            q2.push(c.front());
            t_q2 += c.front().segon();
        }
        c.pop();
    }

    escriureCuaParInt(q1);
    cout << endl;
    escriureCuaParInt(q2);
}