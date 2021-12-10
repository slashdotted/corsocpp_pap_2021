#include "lambda.h"
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using std::cout;

struct Comparatore {
    Comparatore(int v) : m_v{v} {}

    bool operator()(int v) {
        return m_v == v;
    }

    int valore() const {
        return m_v;
    }
private:
    int m_v;
};

struct Comparatore2 {
    Comparatore2(int a, int b, int c)
        : m_a{a}, m_b{b}, m_c{c} {}

    bool operator()(double z) const {
        return (m_a+m_b+m_c+z) < 100;
    }
    
    private:
        int m_a, m_b, m_c;
};

// std::function<tiporitorno(tipoparametri)>
// std::function<bool(double)> foo() {
auto foo() {
    int a{3};
    int b{4};
    int c{5};
    /*return [=,&b,&c] (double z) -> bool {
        return (a+b+c+z) < 100;
    };*/ 
    // devo catturare per valore perché b e c sono
    // sullo stack
    return [=] (double z) -> bool {
        return (a+b+c+z) < 100;
    };
}

void bar(const std::function<bool(double)>& l) {
    cout << l(2.6) << '\n';
}

void bar2(const Comparatore2& c) {
    cout << c(2.6) << '\n';
}


void lalambda() {
    // functor
    Comparatore c7{7};
    Comparatore c13{13};
    cout << std::boolalpha << "=" << c7.valore() << "? " << c7(7) << '\n';
    cout << "=" << c13.valore() << "? " << c13(7) << '\n';

    // lambda
    auto l7 = [] (int v) -> bool {
        return 7 == v;
    };
    int x{13};
    // [=] cattura tutte le variabili per valore
    // [x] cattura x per valore
    auto l13 = [=] (int v) -> bool {
        return x == v;
    };
    cout << "=7? " << l7(7) << '\n';
    cout << "=13? " << l13(7) << '\n';
    x = 7;
    cout << "=13? " << l13(7) << '\n';

    // &x cattura x per riferimento
    // & cattura tutte le variabili per riferimento
    auto l7rif = [&x] (int v) -> bool {
        return x == v;
    };
    cout << "=7? " << l7rif(7) << '\n';
    x = 11;
    cout << "=7? " << l7rif(7) << '\n';

    int a{3};
    int b{4};
    int c{5};
    // a per valore
    // b per riferimento
    // c per riferimento
    auto lambaB = [a,&b,&c] () {
        return a+b+c;
    };
    // tutto per riferimento
    // tranne a per valore
    auto lambaB1 = [&,a] () {
        return a+b+c;
    };
    // tutto per valore
    // tranne b,c per riferimento
    auto lambaB2 = [=,&b,&c] () {
        return a+b+c;
    }; 
    auto mylambda = foo();
    cout << mylambda(3.14) << '\n';

    // Uso delle lambda con algorithm
    std::vector<int> v{1,2,3,4,5,6};

    for(const auto& i : v) {
        cout << i*2 << '\n';
    }

    double factor{3.2};
    std::for_each(v.begin()+1, v.end(), [&factor](const auto& i) {
        cout << i*factor << '\n';
    });

    auto myl = [&factor](const auto& i) {
        cout << i*factor << '\n';
    };
    std::for_each(v.begin()+1, v.end(), myl);

}