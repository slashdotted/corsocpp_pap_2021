#include "smartpointers.h"
#include <memory>
#include <iostream>
#include <vector>


struct Foo {
    Foo(const std::initializer_list<int>& valori) : m_i{0} {
        for(const auto& v : valori) {
            m_i += v;
        }
        std::cout << "Costruisco Foo con initializer list: " << m_i << '\n';
    }

    Foo(int i = 0) : m_i{i}{
        std::cout << "Costruisco Foo: " << i << '\n';
    }

    void bar() const {

    }

    ~Foo() {
        std::cout << "Distruggo Foo: " << m_i << '\n';
    }

    Foo(const Foo& o) : m_i{o.m_i} {
        std::cout << "Costruisco copia Foo: " << m_i << '\n';
    }

    Foo& operator=(const Foo& o) {
        m_i = o.m_i;
        std::cout << "Assegno copia Foo: " << m_i << '\n';
        return *this;
    }

    Foo(Foo&& o) : m_i{o.m_i} {
        std::cout << "Sposto Foo: " << m_i << '\n';
    }

    Foo& operator=(Foo&& o) {
        m_i = o.m_i;
        std::cout << "Assegno spostamento Foo: " << m_i << '\n';
        return *this;
    }

    int m_i;
};

void baz(Foo* f) {

}

void buz(std::unique_ptr<Foo> c) {

}

void buz_ref(std::unique_ptr<Foo>& c) {
    //auto copia{c};
}

void smartpointers() {
    // Unique pointer
    std::cout << "inizio\n";
    {
        std::unique_ptr<Foo> sm{new Foo};
        auto ptr = *sm;
        sm->bar();
        baz(sm.get());
        // buz(sm); // non posso copiare unique_ptr
        buz_ref(sm); // passaggio per riferimento, ok!

        // Esempio, con memory leak
        std::vector<Foo*> lista;
        lista.push_back(new Foo{});
        lista.push_back(new Foo{});
        lista.push_back(new Foo{});
        lista.clear(); // !!!!
        // for (auto& e : lista) { delete e; }; lista.clear();

        std::vector<std::unique_ptr<Foo>> lista2;
        lista2.push_back(std::unique_ptr<Foo>{new Foo{}});
        std::unique_ptr<Foo> k{new Foo{}};
        lista2.push_back(std::move(k));
        auto& k2 = lista2.at(0);
    }


    std::cout << "fine\n";

}