#include "Cubeta.hh"
#include "Lavadora.hh"
#include "Prenda.hh"

void Cubeta::completar_lavadora_pila_it(stack<Prenda>& p, Lavadora& l) {
    
    int tot_weight = l.consultar_peso();
    int max_weight = l.consultar_peso_maximo();
    int weight_to_add = max_weight - tot_weight;

    while(not p.empty() and (p.top().consul_peso() <= weight_to_add)) {

        l.anadir_prenda(p.top());
        weight_to_add -= p.top().consul_peso();
        p.pop();
    }
}

void Cubeta::escribir_pila_prenda(const stack<Prenda>& p) {
    stack<Prenda> p2 = p;

    while(not p2.empty()) {
        Prenda gar = p2.top();
        cout << gar.consul_peso() << ' ' << (gar.consul_color() ? "true" : "false") << endl;

        p2.pop();
    }
}

Cubeta::Cubeta() {
    ropacolor = stack<Prenda> ();
    ropablanca = stack<Prenda> ();
}

Cubeta::Cubeta(const Cubeta& c) {
    ropacolor = c.ropacolor;
    ropablanca = c.ropablanca;
}

void Cubeta::anadir_prenda(const Prenda& p) {
    if(p.consul_color()) {
        ropacolor.push(p);
    }
    else {
        ropablanca.push(p);
    }
}

void Cubeta::completar_lavadora(Lavadora& lav) {
    if(lav.consultar_color()) {
        completar_lavadora_pila_it(ropacolor, lav);
    }
    else {
        completar_lavadora_pila_it(ropablanca, lav);
    }
}

void Cubeta::escribir() const {
    cout << "   Cubeta: \n" << "Ropa de color de la cubeta: \n";
    escribir_pila_prenda(ropacolor);

    cout << "Ropa blanca de la cubeta: \n";
    escribir_pila_prenda(ropablanca);
}