#include "riferimenti.h"
#include <iostream>

using std::cout;

void intro() {
    int i{13};
    int& iref{i};
    //int& irefb; // un riferimento deve essere 
                  // per forza inizializzato
    int* iptr{&i};

    cout << "i=" << i 
         << ", iref=" << iref 
         << ", iptr" << *iptr << '\n';

    i = 17;

    cout << "i=" << i 
         << ", iref=" << iref 
         << ", iptr" << *iptr << '\n';
        
    iref = 21;

    cout << "i=" << i 
         << ", iref=" << iref 
         << ", iptr" << *iptr << '\n';
}

void baz(int x) {
    x = 77;
}

void foo(int& x) {
    x = 77;
}

void foo2(const int& x) {
   
}

void bar(int* x) {
    *x = 77;
}

void bat(int*& k) {
    
}

int val() {
    return 0;
}

void swap(int& x, int& y) {
    int temp{x};
    x = y;
    y = temp;
}

int& bla1(int& x) {
    return x;
}

const int& bla2(const int& x) {
    return x;
}

const int& bla3(int& x) {
    return x;
}

/*int& bla4(const int& x) {
    return x;
}*/

int& bla5() {
    int x{4};
    return x; // Attenzione! Riferimento a variabile locale
}

void riferimenti() {
    intro();
    int a{42};
    int b{88};
    cout << "a=" << a << '\n';
    foo(a);
    //bar(&a);
    cout << "a=" << a << '\n';

    cout << "a=" << a << ",b=" << b << '\n';
    swap(a,b);
    cout << "a=" << a << ",b=" << b << '\n';

    int dati[] {1,2,3,4,5,6};
    for(auto& i : dati) {
        i = 42;
    }

    for(const auto& i : dati) {
        std::cout << i << '\n';
    }

    foo(a);
    foo2(a);
    //foo(val()); // Non posso passare valori "r-value" per riferimento
    foo2(val());
    bar(&a);
    baz(a);

    // foo(4); // Non posso passare valori "r-value" per riferimento
    foo2(4);
    //bar(??);
    baz(4);


}