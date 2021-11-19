#include "docentericercatore.h"

const double& DocenteRicercatore::perc() const noexcept {
    return m_perc;
}

DocenteRicercatore::DocenteRicercatore(const std::string& nome,
            const std::string& istituto,
            int nr,
            const std::string& ciclo,
            const std::string& corso,
            const std::string& area,
            double perc) 
            : Collaboratore{nome,istituto,nr},
              Docente{nome, istituto, nr, ciclo, corso},
              Ricercatore{nome, istituto, nr, area},
              m_perc{perc} {
            }

std::string DocenteRicercatore::classe()  const noexcept {
    return "DocenteRicercatore";
}            