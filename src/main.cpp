#include "frazione.h"
#include <iostream>

using std::cout;

void duplica(const Frazione& f, Frazione& g) {
    g.m_num = f.m_num;
    g.m_den = f.m_den;
}

void stampa(const Frazione& f) {
    cout << f.numeratore() 
         << "/" << f.denominatore() 
         << '\n';
}

int main() {
    Frazione f;
    Frazione* g{new Frazione};
    f.denominatore(4);

    delete g;
}