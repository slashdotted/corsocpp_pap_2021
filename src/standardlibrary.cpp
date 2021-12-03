#include "standardlibrary.h"
#include <initializer_list>
#include <iostream>
#include <vector>
#include <map>
#include <string>

struct Foo {
    Foo(const std::initializer_list<int>& valori) : m_i{0} {
        for(const auto& v : valori) {
            m_i += v;
        }
        std::cout << "Costruisco Foo con initializer list: " << m_i << '\n';
    }

    Foo(int i = 0) : m_i{i} {
        std::cout << "Costruisco Foo: " << i << '\n';
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

void standardlibrary() {
    auto p=Foo{3}; // chiama Foo(initializer_list)
    auto q=Foo(3); // chiama Foo(int)
    std::vector<Foo> v{3,4,5,6,7,8};
    v.reserve(100);
    // equivale a std::vector<Foo> v{Foo{3},Foo{4},Foo{5},Foo{6},Foo{7},Foo{8}};
    v.push_back(10);
    v.clear();
    v.reserve(10);
    v.push_back(1);
    v.push_back(2);
    v.emplace_back(3);
    // Accesso agli elementi
    auto val = v.at(2);
    // Dimensione
    std::cout<< v.size() << '\n';
    for (auto& e : v) {
        // ..
    }
    for (const auto e : v) {
        // ..
    }

    std::map<std::string,Foo> m;
    m["tre"] = 3;
    // m[std::string{"tre"}] = Foo{3}
    auto val2 =  m["tre"];
    auto val3 =  m["quattro"];

    auto exists{true};
    try {
        auto val3b = m.at("quattro");
    } catch(...) {
        // non esiste
        exists = false;
    }
    if (exists) {
        // esiste
    }


    if (m.count("quattro")) {
        // esiste
        auto valore =  m["quattro"];
        // oppure
        auto valore2 = m.at("quattro");
    }

    auto it = m.find("quattro");
    if (it != m.end()) {
        // esiste
        auto valore = *it;
    } else {
        // non esiste
    }

    Foo k{1,2,3,4,5,6};
    // https://en.cppreference.com/w/
}