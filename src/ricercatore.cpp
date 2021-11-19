#include "ricercatore.h"

const std::string& Ricercatore::area() const noexcept {
    return m_area;
}

Ricercatore::Ricercatore(const std::string& nome,
            const std::string& istituto,
            int nr,
            const std::string& area) 
            : Collaboratore{nome,istituto,nr}, m_area{area}  {
            }

std::string Ricercatore::classe()  const noexcept {
    return Collaboratore::classe() + "->" +  "Ricercatore"; // "equivalente" a super in Java
}            