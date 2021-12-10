#include "lambda.h"
#include <iostream>

using std::cout;

struct Comparatore {
    Comparatore(int v) : m_v{v} {}

    bool compara(int v) {
        return m_v == v;
    }
private:
    int m_v;
};


void lalambda() {
    Comparatore c7{7};
    Comparatore c13{13};
    cout << "=7?" << c7.compara(7) << '\n';


}