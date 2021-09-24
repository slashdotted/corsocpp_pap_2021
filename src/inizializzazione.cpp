#include "inizializzazione.h"

void inizializzazione() {
    {
        int valore = 5; // C
        int pi = 3.14;
    }
    {
        int valore(5); // C++ (pre 11)
        int pi(3.14);
    }
    {
        int valore = {5}; // C++ 11 
        // int pi = {3.14}; // Errore: narrowing conversion
    }
    {
        int valore{5}; // C++ 11
        // int pi{3.14}; // Errore: narrowing conversion
        auto pi{3.14};
        auto msg{"ciao mondo"};
    }
}