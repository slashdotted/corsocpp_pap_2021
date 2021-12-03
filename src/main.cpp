#include "mylist.h"
//#include "myclass.h"
#include <iostream>

using std::cout, std::endl;

int main() {
    MyList<int> m{10};
    for(auto i{0u}; i<m.size(); ++i) {
        m[i] = i;
    }
    for(auto i{0u}; i<m.size(); ++i) {
        cout << m[i] << '\n';
    }

    MyList<double> m2{10};
    for(auto i{0u}; i<m2.size(); ++i) {
        m2[i] = 3.14 + i;
    }
    for(auto i{0u}; i<m2.size(); ++i) {
        cout << m2[i] << '\n';
    }
};