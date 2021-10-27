#ifndef DOCENTE_H
#define DOCENTE_H
#include "collaboratore.h"

/*
    Derivazione:
        -public: i metodi public della classe base rimangono public
        -protected: i metodi public della classe base diventano protected nella classe derivata
        -private: i metodi public e protected della classe base diventano private nella classe derivata

    derivazione public per default se dichiaro derivata con "struct"
    derivazione private per default se dichiaro derivata con "class"
*/
struct Docente : public Collaboratore {
    Docente(const std::string& nome,
            const std::string& istituto,
            int nr,
            const std::string& ciclo,
            const std::string& corso);

    const std::string& ciclo() const noexcept;
    const std::string& corso() const noexcept;
    std::string classe()  const noexcept;

protected:
    std::string m_ciclo;
    std::string m_corso;
};
#endif