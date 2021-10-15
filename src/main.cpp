#include "raii.h"
#include <iostream>
#include <memory>

using std::cout;

void foo() {
    //auto s = MySmartPointer{new Settimana};
    //auto s = std::make_unique<Settimana>();

    /// ....
    //bar();
}

void baz(SettimanaH p) {
    // ...
}

int main() {
    /*cout << "Creo Settimana sullo stack\n";
    {
    Settimana s; // stack
    }*/
    /*cout << "Creo Settimana sullo heap\n";
    Settimana *s2{new Settimana}; // heap
    cout << "Distruggo Settimana sullo heap\n";
    delete s2;*/
    cout << "Creo SettimanaH sullo stack\n";
    SettimanaH s3; // stack, giornate su heap
    baz(s3);
    cout << "Dopo baz\n";
    SettimanaH s3b;
    s3b = s3;
    /*cout << "Creo SettimanaH sullo heap\n";
    SettimanaH *s4{new SettimanaH}; // heap, giornate su heap
    cout << "Distruggo SettimanaH sullo heap\n";
    delete s4;*/

    cout << "Fine programma\n";
}