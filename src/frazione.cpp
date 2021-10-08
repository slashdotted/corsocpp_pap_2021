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