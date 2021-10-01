#include "frazione.h"

Frazione::Frazione()
    : Frazione(0) // delegating constructor
{
}

Frazione::Frazione(int n, int d) 
    : m_num{n}, m_den{d} // init-list
{

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