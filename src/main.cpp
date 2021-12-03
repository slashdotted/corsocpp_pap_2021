#include "mylist.h"
#include "myclass.h"
#include <iostream>

using std::cout, std::endl;

int main() {
    MyList m{10};
    for(auto i{0u}; i<m.size(); ++i) {
        m[i] = i;
    }
    for(auto i{0u}; i<m.size(); ++i) {
        cout << m[i] << '\n';
    }
};