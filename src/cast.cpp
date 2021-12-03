#include "cast.h"
#include "collaboratore.h"
#include "docente.h"
#include "docentericercatore.h"
#include <iostream>
#include <vector>
#include <map>

using std::cout;

struct Base {
    //virtual ~Base()= default;
};

struct Derivata : Base {

};

void foo(Collaboratore c) {

}

// const_cast (esempio)
struct Util {
    int calcolaHash(const std::string& c) const {
        Util* non_const_this = const_cast<Util*>(this);
        non_const_this->cache[c] = 42;
        return 42;
    }
private:
    std::map<std::string,int> cache;
};

bool instanceOfDocente(Collaboratore& c) {
    try {
        auto d = dynamic_cast<Docente&>(c);
    } catch (...) {
        return false;
    }
    return true;
}

bool instanceOfDocenteRicercatore(Collaboratore& c) {
    try {
        auto d = dynamic_cast<DocenteRicercatore&>(c);
    } catch (...) {
        return false;
    }
    return true;
}

double totalePercentualeRicerca(std::vector<Collaboratore*> l) {
    double totale{0.0};
    for (auto c : l) {
        if (instanceOfDocenteRicercatore(*c)) {
            auto d = dynamic_cast<DocenteRicercatore&>(*c);
            totale += d.perc();
        }
    }
    return totale;
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
        //Docente d2 = static_cast<Docente>(c2); // non posso riconvertire il valore in Docente (manca una parte dell'oggetto)
        //Docente& d3 = static_cast<Docente&>(c2); // non possibile, derivazione virtual
        //DocenteRicercatore  dr1 = static_cast<DocenteRicercatore>(d);

        // Upcasting
        Docente& drd = static_cast<Docente&>(dr);
        Docente* drd2 = static_cast<Docente*>(&dr);

        // Downcasting
        DocenteRicercatore& drd3 = static_cast<DocenteRicercatore&>(drd);
        DocenteRicercatore* drd4 = static_cast<DocenteRicercatore*>(drd2);

        // Attenzione, downcasting non valido ma l'errore non viene segnalato
        DocenteRicercatore& dr2 = static_cast<DocenteRicercatore&>(d);
        DocenteRicercatore* dr3 = static_cast<DocenteRicercatore*>(&d);

        cout << dr2.perc() << ", " << dr2.area() << '\n';
    }
    {
        // Dynamic cast
        Collaboratore c{"Elvis", "SI", 13};
        Docente d{"Amos", "ISIN", 42, "Info", "C++"};
        Ricercatore r{"Vanni", "ISIN", 78, "DS"};
        DocenteRicercatore dr{"Roberto", "ISIN", 33, "Info", "DB", "Spaziale", 0.5};

        // Collaboratore c2 = dynamic_cast<Collaboratore>(d); // non posso convertire valori

        // Upcasting
        try {
            Collaboratore& c3 = dynamic_cast<Collaboratore&>(d);
        } catch(...) {
            // Cast non valido
            cout << "Cast non valido\n";
        }
        Collaboratore* c4 = dynamic_cast<Collaboratore*>(&d);
        if (c4 == nullptr) {
            // Cast non valido
            cout << "Cast non valido\n";
        }

        // Downcasting
        try {
            Collaboratore& c3 = dynamic_cast<Collaboratore&>(d);
            Docente& c5 = dynamic_cast<Docente&>(c3);
        } catch(...) {
            // Cast non valido
            cout << "Cast non valido\n";
        }
        Collaboratore* c6 = dynamic_cast<Collaboratore*>(&d);
        Docente* c7 = dynamic_cast<Docente*>(c6);
        if (c7 == nullptr) {
            // Cast non valido
            cout << "Cast non valido\n";
        }

        // Downcasting non valido viene segnalato
        try {
            DocenteRicercatore& dr2 = dynamic_cast<DocenteRicercatore&>(d);
        } catch (...) {
            cout << "Cast non valido riga 83\n";
        }

        DocenteRicercatore* dr3 = dynamic_cast<DocenteRicercatore*>(&d);

        if (dr3 == nullptr) {
            // Cast non valido
            cout << "Cast non valido riga 90\n";
        }

        //
        Derivata derivata;
        Base* base = dynamic_cast<Base*>(&derivata);
        Derivata* derivata2 = dynamic_cast<Derivata*>(base);
        // Errore, il tipo Base non è polimorfico
        // Soluzione: aggiungere almeno un metodo virtual a Base
        // p.es virtual ~Base() = default;
    }
    {
        // const_cast
        const std::vector<int> lista{1,2,3,4,5,6};
        //lista.push_back(3);
        std::vector<int>& lista_non_const = const_cast<std::vector<int>&>(lista);
        lista_non_const.push_back(6);
    }

}