#include "namespaces.h"
#include <iostream>

//using namespace std;
namespace supsi {
namespace dacd {
void foo() {
    std::cout << "supsi dacd" << std::endl;
}
}
}

// nested namespaces (C++17)
namespace supsi::dti {
void foo() {
    std::cout << "supsi dti" << std::endl;
}
}

namespace usi {
void foo() {
    std::cout << "usi" << std::endl;
}
}

namespace std {
void foo() {

}
}

// Alias di namespace
namespace ab = usi;
//using namespace std;
using std::cout; // importo puntualmente un simbolo nel namespace globale
using std::cerr;
using std::endl;

void namespaces() {
    ab::foo();
    cerr << "Ciao mondo" << endl;

}