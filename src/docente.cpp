#include "docente.h"

const std::string& Docente::ciclo() const noexcept {
    return m_ciclo;
}
const std::string& Docente::corso() const noexcept {
    return m_corso;
}

Docente::Docente(const std::string& nome,
            const std::string& istituto,
            int nr,
            const std::string& ciclo,
            const std::string& corso) 
            : Collaboratore{nome,istituto,nr}, m_ciclo{ciclo}, m_corso{corso}  {
            }

std::string Docente::classe()  const noexcept {
    return "Docente";
}            