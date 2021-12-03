//#include "mylist.h"
#include "myclass.h"
#include "mylist2.h"
#include <iostream>
#include <string>

using std::cout, std::endl;

void foo(MyList2<int,10>& m) {

}

// Template di funzione
template<typename T, typename U>
bool massimo(T x, U y) {
    return x > y;
}

// Template di funzione
template<>
bool massimo<const std::string&, const std::string&>(const std::string& x, const std::string& y) {
    return x.size() > y.size();
}

int main() {
    std::cout << massimo(3.14,2) << std::endl;
    std::cout << massimo(2,2) << std::endl;
    std::cout << massimo(2,3.14) << std::endl;
    std::cout << massimo(std::string{"ciao"},std::string{"mondo"}) << std::endl;




    /*MyClass<int, double> mc{5,3.14};
    mc.printMessage();

    MyClass2<int, double> mc2{5,3.14};
    MyClass2<int> mc3{5,3};
    MyClass2b<> mc4{42,5};*/
    MyClass2<double, std::string> mc5{6.2,"true"};
    mc5.printMessage();

    MyClass2<std::string, double> mc6{"true", 6.2};
    mc6.printMessage();

    MyClass2<std::string, std::string> mc7{"true", "false"};
    mc7.printMessage();

    MyClass2<double, double> mc8{6.2,3.14};
    mc8.printMessage();

  /*  MyList2<int, 20> ml;
    MyList2<int, 10> ml2;*/






};