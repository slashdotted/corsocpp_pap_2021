#include "collaboratore.h"
#include "docente.h"
#include <iostream>

using std::cout;

void foo(const Collaboratore& c) {
    cout << "Collaboratore:" << c.nome() << "," << c.istituto() << "," << c.nr() << "," << c.classe();
}

int main() {
    Collaboratore c{"Elvis", "DTI", 15};
    Docente d{"Roberto", "DTI", 42, "Info", "Basi Dati"};
    cout << "Collaboratore:" << c.nome() << "," << c.istituto() << "," << c.nr() << "," << c.classe();
    cout << "\n\n";
    cout << "Docente:" << d.nome() << "," << d.istituto() << "," << d.nr()
     << "," << d.ciclo() << "," << d.corso() << "," << d.classe(); 
     cout << "\n\n";
    foo(c);
    cout << "\n\n";
    foo(d);
}