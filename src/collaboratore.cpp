#include "collaboratore.h"

Collaboratore::Collaboratore(const std::string& nome,
                const std::string& istituto,
                int nr) : m_nome{nome}, m_istituto{istituto}, m_nr{nr} {}

const std::string& Collaboratore::nome() const noexcept {
    return m_nome;
}

const std::string& Collaboratore::istituto() const noexcept {
    return m_istituto;
}

int Collaboratore::nr() const noexcept {
    return m_nr;
}

std::string Collaboratore::classe()  const noexcept {
    return "Collaboratore";
}