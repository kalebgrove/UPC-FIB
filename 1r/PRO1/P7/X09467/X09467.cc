#include <iostream>
#include <vector>

using namespace std;

// Pre: 0 <= i <= V.size()-3
// Retorna si V_{i}, V_{i+1}, V_{i+2} es rampa
bool es_rampa(const vector <int>& V, int i) {
    return (V[i+2] - V[i+1]) * (V[i+1] - V[i]) > 0; // comprova si (V[i], V[i+1]), (V[i+1], V[i+2]) mateixa direccio
}

// Pre: V.size() >= 3
// Retorna un vector amb les posicions de les rampes
vector <bool> pos_rampas(const vector <int>& V) {
    vector<bool> p_r(V.size());
    for (int i = 0; i < V.size()-2; ++i)  p_r[i] = es_rampa(V, i);
    return p_r;
}

// Pre: B.size() >= 3
// Retorna el nombre de conflictes entre rampes
int pot_conflictives(const vector <bool>& B) {
    int pot_conf = 0;
    for (int i = 0; i < B.size()-3; ++i) {
        if (B[i]) { // si tenim rampa a i, comprovem les dues seguents posicions
            for (int j = i + 1; j < i + 3; ++j) {
                if (B[j]) ++pot_conf;
            }
        }
    }
    return pot_conf;
}

void escriure_resultat(const vector<bool> posicions, int pot_conf) {
    cout << "posicions amb rampa:";
    for (int i = 0; i < int(posicions.size()); ++i) {
        if (posicions[i])  cout << ' ' << i;
    }
    cout << endl;
    
    cout << "potencialment conflictives: " << pot_conf << endl;
    cout << "---" << endl;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        
        vector<bool> posicions = pos_rampas(v);
        int pot_conf = pot_conflictives(posicions);
        
        escriure_resultat(posicions, pot_conf);
    }
}