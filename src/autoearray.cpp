#include "autoearray.h"
#include <iostream>

auto somma(int x, int y) {
    return x+y;
}

void autoearray() {
    auto x{100};
    auto s{somma(6,2)};
    auto k = somma(6,2);

    int dati[] {1,2,3,4,5,6};
    for(auto i : dati) {
        std::cout << i << '\n';
    }

}