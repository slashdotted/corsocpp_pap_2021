#include "eccezioni.h"
#include <iostream>
#include <memory>
using std::cout;

struct Foo {
    Foo() { cout << "Costruisco Foo\n";}
    ~Foo() { cout << "Distruggo Foo\n";}
};

void bar() {
    throw 13;
}

void baz() noexcept {
    cout << "Inizio baz\n";
    bar();   
    cout << "Fine baz\n";
}

void foo() {
    //Foo i;
    auto i{std::make_unique<Foo>()};
    //auto* i{new Foo};
    baz();
    // 
    //delete i;
}

void eccezioni() {
    try {
        foo();
    } catch(int ex) {
        cout << "Exception: " << ex << '\n';
        throw; // rilancia l'eccezione
    } catch(const char* ex) {
        cout << "Exception: " << ex << '\n';
    }
    // non esiste finally
}