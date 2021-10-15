#include <iostream>
#include <string>

struct Giornata {
    explicit Giornata(const std::string& g) : m_g{g} {
        std::cout << "Costruisco giornata " << g << std::endl;
    }

    ~Giornata() {
         std::cout << "Distruggo giornata " << m_g << std::endl;
    }

    std::string m_g;

    Giornata clone() const {
        return Giornata{m_g};
    }

// impedisco la copia
//    private:
//    Giornata(const Giornata& o) {}
//    Giornata& operator=(const Giornata& o) { return *this;}

//    Giornata(const Giornata& o) = delete;
//    Giornata& operator=(const Giornata& o) = delete;
};

struct Settimana {
    Settimana() {
        std::cout << "Costruisco settimana" << std::endl;
    }

    ~Settimana() {
         std::cout << "Distruggo settimana " << std::endl;
    }

    Giornata m_lu{"lunedì"};
    Giornata m_ma{"martedì"};
    Giornata m_me{"mercoledì"};
    Giornata m_gi{"giovedì"};
    Giornata m_ve{"venerdì"};
    Giornata m_sa{"sabato"};
    Giornata m_do{"domenica"};
};

struct SettimanaH {
    SettimanaH() 
        : m_lu{new Giornata{"lunedì"}},
          m_ma{new Giornata{"martedì"}},
          m_me{new Giornata{"mercoledì"}},
          m_gi{new Giornata{"giovedì"}},
          m_ve{new Giornata{"venerdì"}},
          m_sa{new Giornata{"sabato"}},
          m_do{new Giornata{"domenica"}}
        {
        std::cout << "Costruisco settimana" << std::endl;
    }

    // costruttore di copia
    SettimanaH(const SettimanaH& o)         
        : m_lu{new Giornata{o.m_lu->m_g}},
          m_ma{new Giornata{o.m_ma->m_g}},
          m_me{new Giornata{o.m_me->m_g}},
          m_gi{new Giornata{o.m_gi->m_g}},
          m_ve{new Giornata{*o.m_ve}}, // mi appoggio al costruttore di copia di giornata
          m_sa{new Giornata{*o.m_sa}}, // mi appoggio al costruttore di copia di giornata
          m_do{new Giornata{*o.m_do}} { // mi appoggio al costruttore di copia di giornata
    }

    // operatore di assegnamento di copia
    SettimanaH& operator=(const SettimanaH& o) {
        m_lu->m_g = o.m_lu->m_g;
        m_ma->m_g = o.m_ma->m_g;
        m_me->m_g = o.m_me->m_g;
        m_gi->m_g = o.m_gi->m_g;
        *m_ve = *o.m_ve;
        *m_sa = *o.m_sa;
        *m_do = *o.m_do;
        return *this;
    }



    ~SettimanaH() {
        delete m_lu;
        delete m_ma;
        delete m_me;
        delete m_gi;
        delete m_ve;
        delete m_sa;
        delete m_do;
        std::cout << "Distruggo settimana " << std::endl;
    }

    Giornata* m_lu;
    Giornata* m_ma;
    Giornata* m_me;
    Giornata* m_gi;
    Giornata* m_ve;
    Giornata* m_sa;
    Giornata* m_do;
};

struct MySmartPointer {
    MySmartPointer(Settimana* s) : m_s{s} {}

    ~MySmartPointer() {
        delete m_s;
    }

    Settimana *m_s;
};