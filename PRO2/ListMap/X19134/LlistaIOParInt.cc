#include "LlistaIOParInt.hh"

using namespace std;

void LlegirLlistaParInt(list<ParInt>& l) {
    int x, y;
    while(cin >> x >> y and (x != 0 or y != 0)) {
        l.emplace_back(x, y);
    }
}