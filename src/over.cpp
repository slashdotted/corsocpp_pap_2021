#include "over.h"
#include <iostream>

using std::cout, std::endl;

class ExampleOverloading {
public:
       void f(double x)
       {
               cout << "f(double x)" << endl;
       }
       
       void f(int x)
       {
               cout << "f(int x)" << endl;
       }
};

void overloading()
{
       ExampleOverloading e;
       e.f(3.2);
       e.f(3);
}

// *******************************************************

class BaseOverriding {
public:
       virtual void f(double x)
       {
               cout << "Base::f(double x)" << endl;
       }
};
class DerivedOverriding : public BaseOverriding {
public:
       void f(double x)
       {
               cout << "Derived::f(double x)" << endl;
       }       
};
void overriding()
{
       DerivedOverriding e;
       e.f(3.2);
       e.f(3);
}

// *******************************************************

class BaseHiding {
public:
       virtual void f(double x)
       {
               cout << "Base::f(double x)" << endl;
       }
};
class DerivedHiding : public BaseHiding {
public:
       void f(int x)
       {
               cout << "Derived::f(int x)" << endl;
       }       
};

void hiding()
{
       DerivedHiding e;
       e.f(3.2);
       e.f(3);
}