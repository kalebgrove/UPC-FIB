#include <iostream>
#include <vector>

using namespace std;

struct Assignatura {
    string nom;                //Name of the subject being taken.
    double nota;                //Grade that the student has in given subject.
};

struct Alumne {
    string nom;                //Student's name.
    int dni;                    //Student's identification number.
    vector<Assignatura> ass;       //List of subjects that the student participates in.
};

double nota(const vector<Alumne>& alumns, int dni, string nom) {
    for(int i = 0; i < alumns.size(); ++i) {
        if(dni == alumns[i].dni) {
            for(int j = 0; j < alumns[i].ass.size(); ++j) {
                if(nom == alumns[i].ass[j].nom) {
                    if(alumns[i].ass[j].nota != -1) return alumns[i].ass[j].nota;
                }
            }
        }
    }
    return -1;
}

int mitjana(const vector<Alumne>& alumns) {
    double sum = 0;
    int ctr = 0;
    for(int i = 0; i < alumns.size(); ++i) {
        for(int j = 0; j < alumns[i].ass.size(); ++j) {
            if(alumns[i].ass[j].nota != -1) {
                sum += alumns[i].ass[j].nota;
                ++ctr;
            }
        }
    }
    if(ctr == 0) return -1;
    else return sum/ctr;
}

int compta(const vector<Alumne>& alumns, int dni, string nom, int& com) {
    int count = 0;
    double average = mitjana(alumns);
    int i = 0; 
    while(i < alumns.size() and alumns[i].dni != dni) ++i;
    
    if(i == alumns.size()) return 5;
    else{
        for(int j = 0; j < alumns[i].ass.size(); ++j) {
            if(nom == alumns[i].ass[j].nom and alumns[i].ass[j].nota < average) ++com;
        }
    }
    for(int i = 0; i < alumns.size(); ++i) {
        
    }
    return com;
}

int main() {
    int n;
    cin >> n;

    vector<Alumne> alumns;
    for(int i = 0; i < n; ++i) {
        cin >> alumns[i].nom;
        cin >> alumns[i].dni;
        int n_sub;
        cin >> n_sub;
        for(int j = 0; j < n_sub; ++j) {
            cin >> alumns[i].ass[j].nom;
            cin >> alumns[i].ass[j].nota;
        }
    }

    string nom;
    int identificador;
    while(cin >> identificador >> nom) {
        double grade = nota(alumns, identificador, nom);


    }
}