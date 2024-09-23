#include "Lavadora.hh"
#include "Prenda.hh"
#include "Cubeta.hh"

Lavadora::Lavadora() {
    ini = false;
}

void Lavadora::inicializar(int pmax, bool col) {
    ini = true;
    this->col = col;
    pesmax = pmax;
    pes = 0;
    prendas = list<Prenda>();
}

void Lavadora::anadir_prenda (const Prenda& p) {
    prendas.push_back(p);
    pes += p.consul_peso();
}

void Lavadora::lavado() {
    ini = false;
}

bool Lavadora::esta_inicializada() const {
    return ini;
}

bool Lavadora::consultar_color() const {
    return col;
}

int Lavadora::consultar_peso() const {
    return pes;
}

int Lavadora::consultar_peso_maximo() const {
    return pesmax;
}

void Lavadora::escribir() const {
    if(ini) {
        cout << "Lavadora de " << (this->consultar_color() ? "color" : "blanco") << ", con peso actual " << this->consultar_peso();
        cout << " y peso maximo " << this->consultar_peso_maximo() << "; sus prendas son\n";
        list<Prenda>::const_iterator it = prendas.begin();

        while(it != prendas.end()) {
            cout << it->consul_peso() << ' ' << (it->consul_color() ? "true" : "false") << endl;
            ++it;
        }
    }
    else {
        cout << "Lavadora no inicializada" << endl;
    }
}