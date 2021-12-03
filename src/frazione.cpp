#include "frazione.h"

unsigned int Frazione::m_istanze = 0; // storage

Frazione::Frazione()
    : Frazione{0} // delegating constructor
{
    // Frazione{0}; // NO! (Crea un oggetto temporaneo)
}

Frazione::Frazione(int n, int d)
    : m_num{n}, m_den{d} // init-list
{
    ++m_istanze;
}

const int& Frazione::numeratore() const {
    //return this->m_num;
    return m_num;
}

const int& Frazione::denominatore() const {
    return m_den;
}

void Frazione::numeratore(int num) {
    m_num = num;
}

void Frazione::denominatore(int den) {
    m_den = den;
}

Frazione& Frazione::operator += (const Frazione& g) {
    int temp_num { g.m_num * m_den };
    m_den *= g.m_den;
    m_num *= g.m_den;
    m_num += temp_num;
    return *this;
}


Frazione& Frazione::operator -= (const Frazione& g) {
    int temp_num { g.m_num * m_den };
    m_den *= g.m_den;
    m_num *= g.m_den;
    m_num -= temp_num;
    return *this;
}