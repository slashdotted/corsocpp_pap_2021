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

std::ostream& operator << (std::ostream& o, const Frazione& f) {
    o  << f.numeratore() 
         << "/" << f.denominatore();
    return o;
}

Frazione operator+(Frazione a, const Frazione& b) {
    return a += b;
}

Frazione operator-(Frazione a, const Frazione& b) {
    return a -= b;
}

struct Lista {
    // Con explicit evito le conversioni automatiche
    explicit Lista(int spazio_da_riservare) {}

};

void foo(int x, Lista l) {

}

int main() {
    Frazione f{3,4};
    Frazione g{5,2};
    f += g; // f.operator+=(g)
    Frazione h{f + g}; //f.operator+(g)

    Frazione k = f + 2; // conversione implicita a Frazione{2}
    // equivale a Frazione k = f.operator+(Frazione{2})
    Frazione l = 2 + f;
    // equivale a Frazione l = 2.operator+(f)

    // Lista z{100};
    // foo(4,0);
    cout << f << "Hello world" << 2 << 3 << std::endl;
    // equivale a ((((cout << f) << "Hello world") << 2) << 3) << std::endl;  
}