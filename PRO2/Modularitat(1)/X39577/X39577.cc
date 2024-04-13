/* Mitjanes selectives

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include "Estudiant.hh"
#include <set>

using namespace std;

int main() {
    int m, n, s;
    set<int> subjects;

    cin >> m >> n >> s;

    int subj;
    for(int i = 0; i < s; ++i) {
        cin >> subj;
        subjects.insert(subj);
    }

    int dni;
    for(int i = 0; i < m; ++i) {
        cin >> dni;

        double sum = 0;
        double grade;
        for(int j = 0; j < n; ++j) {
            cin >> grade;
            if(subjects.count(j+1)) {
                sum += grade;
            }
        }
        cout << dni << ' ' << double(sum)/s << endl;
    }
}