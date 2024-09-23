#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> Row;
typedef vector<Row> Rectangle;

#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> Fila ;
typedef vector<Fila> Rectangle ;

void dimensions_minimes(char c, const Rectangle& r, int& fils, int& cols) {

    fils = 1 ;
    cols = 1 ;

    int i_min = r.size() - 1 ;
    int i_max = 0 ;
    int j_min = r[0].size() - 1 ;
    int j_max = 0 ;
    bool i_minima = false ;
    int k = 0 ;

    while (not i_minima and k < r.size()) {
        int j = 0 ;

        while (not i_minima and j < r[0].size()) {
            if (r[k][j] == c) {
                i_min = k ;
                i_minima = true ;
            }
            ++j ;
        }
        ++k ;
    }
    bool j_minima = false ;
    int m = 0 ;

    while (not j_minima and m < r[0].size()) {
        int i = 0 ;

        while (not j_minima and i < r.size()) {
            if (r[i][m] == c) {
                j_min = m ;
                j_minima = true ;
            }
            ++i ;
        }
        ++m ;
    }
    bool i_maxima = false ;
    int i = r.size() - 1 ;

    while (not i_maxima and i >= 0) {
        int j = r[0].size() - 1 ;

        while (not i_maxima and j >= 0) {
            if (r[i][j] == c) {
                i_max = i ;
                i_maxima = true ;
            }
            --j ;
        }
        --i ;
    }
    bool j_maxima = false ;
    int j = r[0].size() - 1 ;

    while (not j_maxima and j >= 0) {
        int l = r.size() - 1 ;

        while (not j_maxima and l >= 0) {
            if (r[l][j] == c) {
                j_max = j ;
                j_maxima = true ;
            }
            --l ;
        }
        --j ;
    }
    cols = cols + j_max - j_min ;
    fils = fils + i_max - i_min ;
}