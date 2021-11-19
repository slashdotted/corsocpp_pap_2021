#include "cast.h"
#include "collaboratore.h"
#include "docente.h"
#include "docentericercatore.h"

void foo(Collaboratore c) {

}

void cast() {
    {
        // Static cast
        Collaboratore c{"Elvis", "SI", 13};
        Docente d{"Amos", "ISIN", 42, "Info", "C++"};
        Ricercatore r{"Vanni", "ISIN", 78, "DS"};
        DocenteRicercatore dr{"Roberto", "ISIN", 33, "Info", "DB", "Spaziale", 0.5};
        foo(d);
        Collaboratore c2 = static_cast<Collaboratore>(d);

        Collaboratore& c3 = static_cast<Collaboratore&>(d);
        Collaboratore* c4 = static_cast<Collaboratore*>(&d);

        //DocenteRicercatore& dr = static_cast<DocenteRicercatore&>(c3);
        Docente& d1 = static_cast<Docente&>(dr); // upcasting
        DocenteRicercatore& dr1 = static_cast<DocenteRicercatore&>(d1); // downcasting
    }

}