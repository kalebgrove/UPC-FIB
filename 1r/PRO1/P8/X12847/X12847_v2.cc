#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<vector<bool>> Tauler;
const int N = 10 ;

void dibuixar_tauler(const Tauler& tauler) {

    cout << "  12345678910" << endl ;

    for (int i = 0 ; i < N ; ++i) {
        cout << char(int('a') + i) << " " ;

        for (int j = 0 ; j < N ; ++j) {
            if (tauler[i][j]) cout << "X" ;
            else cout << "." ;        
        }
        cout << endl ;
    }
}

void colocar_vaixell(Tauler& tauler) {

    char c1 , orientation ;
    int j , mida ;
    cin >> c1 >> j >> mida >> orientation ;

    int i = int(c1 - 'a') ;
    j = j - 1 ;

    if (orientation == 'h') {
        for (int k = 0 ; k < mida ; ++k) {
            tauler[i][j+k] = true ;
        }
    }
    else {
        for (int k = 0 ; k < mida ; ++k) {
            tauler[i+k][j] = true ;
        }
    }
}

int min(int a, int b) {

    if (a < b) return a ;
    return b ;
}

int max(int a, int b) {

    if (a > b) return a ;
    return b ;
}

bool trobar_horitzontal(const Tauler& tauler, int i, int from, int to) {

    for (int j = from ; j <= to ; ++j) {
        if (tauler[i][j]) return true ;
    }
    return false ;
}

bool trobar_vertical(const Tauler& tauler, int j, int from, int to) {

    for (int i = from ; i <= to ; ++i) {
        if (tauler[i][j]) return true ;
    }
    return false ;
}

int calcular_distancia(const Tauler& tauler, int i0, int j0) {

    int dist = 1;

    while (dist <= 10) {
        // busquem la part de dalt
        if (i0 - dist >= 0) {
            if (trobar_horitzontal(tauler, i0-dist, max(0, j0-dist), min(j0+dist, N-1))) return dist ;
        }
        // busquem la part de baix
        if (i0 + dist < N) {
            if (trobar_horitzontal(tauler, i0+dist, max(0, j0-dist), min(j0+dist, N-1))) return dist ;
        }
        // busquem la part esquerra
        if (j0 - dist >= 0) {
            if (trobar_vertical(tauler, j0-dist, max(0, i0-dist), min(i0+dist, N-1))) return dist ;
        }
        // busquem la part dreta
        if (j0 + dist < N) {
            if (trobar_vertical(tauler, j0+dist, max(0, i0-dist), min(i0+dist, N-1))) return dist ;
        }
        ++dist ;
    }
    return dist ;
}

void processar_tirada(const Tauler& tauler, int i, int j) {

    cout << char(int('a') + i) << j + 1 ;

    if (tauler[i][j]) {
        cout << " tocat!" << endl ;
    }
    else {
        cout << " aigua! vaixell mes proper a distancia " << calcular_distancia(tauler, i, j) << endl ;
    }
}

int main () {

    Tauler tauler = Tauler(N, vector<bool>(N, false)) ;

    for (int i = 0 ; i < 10 ; ++i) colocar_vaixell(tauler) ;
    dibuixar_tauler(tauler) ;
    cout << endl ;

    char c ;
    int j ;

    while (cin >> c >> j) {
        int i = int(c - 'a') ;
        j = j - 1 ;
        processar_tirada(tauler, i, j) ;
    }
}