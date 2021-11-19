#ifndef RICERCATORE_H
#define RICERCATORE_H

#include "collaboratore.h"

struct Ricercatore : public virtual Collaboratore {
        Ricercatore(const std::string& nome,
            const std::string& istituto,
            int nr,
            const std::string& area);

    const std::string& area() const noexcept;
    std::string classe()  const noexcept;

protected:
    std::string m_area;
};



#endif
