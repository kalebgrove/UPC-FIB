/* Mitjanes selectives 2

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "Estudiant.hh"
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(Estudiant& est1, Estudiant& est2) {
    if(est1.consultar_nota() != est2.consultar_nota()) return est1.consultar_nota() > est2.consultar_nota();
    return est1.consultar_DNI() < est2.consultar_DNI();
}

int main() {
    int m, n, s;

    cin >> m >> n >> s;
    vector<Estudiant> vec;
    set<int> sbj;

    for(int i = 0; i < s; ++i) {
        int num;
        cin >> num;
        sbj.insert(num);
    }

    for(int i = 0; i < m; ++i) {
        int dni;
        cin >> dni;
        Estudiant est = Estudiant(dni);
        vec.push_back(est);

        double sum = 0;
        for(int j = 0; j < n; ++j) {
            double grade;
            cin >> grade;

            if(sbj.count(j+1) > 0) {
                sum += grade;
            }
        }
        double avg = double(sum)/s;
    //cout << vec.size() << endl;
        vec[i].afegir_nota(avg);
    }
    sort(vec.begin(), vec.end(), comp);

    int size = vec.size();
    for(int i = 0; i < size; ++i) {
        cout << vec[i].consultar_DNI() << ' ' << vec[i].consultar_nota() << endl;
    }
}