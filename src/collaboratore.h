#ifndef COLLABORATORE_H
#define COLLABORATORE_H
#include <string>

class Collaboratore {
public:
    Collaboratore(const std::string& nome,
                  const std::string& istituto,
                  int nr);

    const std::string& nome() const noexcept;
    const std::string& istituto() const noexcept;
    int nr() const noexcept;
    virtual std::string classe() const noexcept;

protected:
    std::string m_nome;
    std::string m_istituto;
    int m_nr;
};
#endif