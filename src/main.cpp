#include "standardlibrary.h"
#include "smartpointers.h"
#include "eccezioni.h"
#include <iostream>

using std::cout;

int main() {
    //standardlibrary();
    //smartpointers();
    try {
        eccezioni();
    } catch(...) {
        cout << "Problema al programma\n";
    }
    cout << "Fine programma\n";
}