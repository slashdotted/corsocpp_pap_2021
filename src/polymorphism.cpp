#include "polymorphism.h"

#include <iostream>
using std::cout, std::endl;

class Base {
       public:
               void bar() {
                       cout << "\tBase::bar()" << endl;
               }
};
class Derived : public Base {
       public:
               virtual void bar() {
                       cout << "\tDerived::bar()" << endl;
               }
};
class SottoDerived : public Derived {
       public:
               void bar() {
                       cout << "\tSottoDerived::bar()" << endl;
               }
};
void polymorphism()
{
       SottoDerived sd;
       Base& bd {sd};
       Derived& dd {sd};
       
       bd.bar();
       dd.bar();
}