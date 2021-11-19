#ifndef COLLABORATORE_H
#define COLLABORATORE_H
#include <string>

class AbstractBase {
    public:
        // metodo pure virtual
        virtual std::string classe() const noexcept = 0;
};

class Collaboratore : public AbstractBase {
public:
    Collaboratore(const std::string& nome,
                  const std::string& istituto,
                  int nr);

    //Collaboratore() = default;

    const std::string& nome() const noexcept;
    const std::string& istituto() const noexcept;
    int nr() const noexcept;
    // Ricordarsi di ri-dichiarare i metodi pure-virtual
    std::string classe() const noexcept;

protected:
    std::string m_nome;
    std::string m_istituto;
    int m_nr;
};
#endif