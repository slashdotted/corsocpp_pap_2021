#include "collaboratore.h"
#include "docente.h"
#include "ricercatore.h"
#include "docentericercatore.h"
#include <iostream>
#include "cast.h"

using std::cout, std::endl;

void foo(const Ricercatore& r) {
    cout << "Indirizzo di Ricercatore:" << &r << '\n';
}

void bar(const Docente& r) {
    cout << "Indirizzo di Docente:" << &r << '\n';
}

void baz(const Collaboratore& r) {
    cout << "Indirizzo di Collaboratore:" << &r << '\n';
}

int main() {
    Collaboratore c{"Elvis", "SI", 13};
    Docente d{"Amos", "ISIN", 42, "Info", "C++"};
    Ricercatore r{"Vanni", "ISIN", 78, "DS"};
    DocenteRicercatore dr{"Roberto", "ISIN", 33, "Info", "DB", "Spaziale", 0.5};

    cout << "Indirizzo di Ricercatore:" << &r << '\n';
    foo(r);
    baz(r);

    cout << "Nome:" << dr.nome() << "\n";
    cout << "Indirizzo di DocenteRicercatore:" << &dr << '\n';
    foo(dr);
    bar(dr);
    baz(dr);

    cast();
};