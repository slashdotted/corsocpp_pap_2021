#ifndef DOCENTERICERCATORE_H
#define DOCENTERICERCATORE_H
#include "docente.h"
#include "ricercatore.h"

struct DocenteRicercatore : public Docente, public Ricercatore {
    DocenteRicercatore(const std::string& nome,
            const std::string& istituto,
            int nr,
            const std::string& ciclo,
            const std::string& corso,
            const std::string& area,
            double perc);

    const double& perc() const noexcept;
    std::string classe()  const noexcept;

protected:
    double m_perc;
};
#endif