#include "frazione.h"
#include <iostream>

using std::cout;

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