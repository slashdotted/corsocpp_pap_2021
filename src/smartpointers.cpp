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

void unique() {
    // Unique pointer
    std::cout << "inizio\n";
    {
        std::unique_ptr<Foo> sm{new Foo};
        auto sm2{std::make_unique<Foo>(/* ev. parametri del costruttore di Foo */)};
        auto ptr = *sm;
        sm->bar();
        (*sm).bar();
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

        {
            std::unique_ptr<Foo> k{new Foo{}};
            // lista2.push_back(k); // Non posso copiare unique_ptr
            lista2.push_back(std::move(k)); // trasferisco la proprietà a lista2
        }

        auto& k2 = lista2.at(0);

        // Rilascio del puntatore
        auto ptr2{sm2.get()};
        sm2.release();
        delete ptr2;
    }


    std::cout << "fine\n";

}

void fun(std::shared_ptr<Foo> v) {
}

void fun_ref(std::shared_ptr<Foo>& v) {
}

void shared() {
    std::shared_ptr<Foo> sp{new Foo};
    auto sp2{std::make_shared<Foo>(/* ev. argomenti costruttore Foo */)};
    sp2->bar();
    (*sp2).bar();
    auto sp2copy = sp2;
    fun(sp2);
    fun_ref(sp2);

    std::vector<std::shared_ptr<Foo>> lista2;
    lista2.push_back(std::shared_ptr<Foo>{new Foo{}});

    {
        std::shared_ptr<Foo> k{new Foo{}};
        lista2.push_back(k); // Posso copiare shared_ptr
        lista2.push_back(std::move(k)); // trasferisco la proprietà a lista2
    }
}

void smartpointers() {
    unique();
    shared();
}