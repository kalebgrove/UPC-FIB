#include "CuaIOParInt.hh"

using namespace std;

void llegirCuaParInt(queue<ParInt>& c){
    int x, y;

    while(cin >> x >> y and (x != 0 or y != 0)) {
        c.push(ParInt(x, y));
    }
}

void escriureCuaParInt(queue<ParInt> c){
    while(c.size() > 0) {
        cout << c.front().primer() << ' ' << c.front().segon() << endl;
        c.pop();
    }
}