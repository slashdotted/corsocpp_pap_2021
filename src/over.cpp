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
       void f(double x) override
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
       using BaseHiding::f;

       virtual void f(int x)
       {
               cout << "Derived::f(int x)" << endl;
       } 

       /*void f(double x) override {
              BaseHiding::f(x);
       } */   
};

class DoubleDerivedHiding : public DerivedHiding {
       public:
       using DerivedHiding::f;

       void f(int x) override
       {
               cout << "Derived::f(int x)" << endl;
       } 
};

void hiding()
{
       DerivedHiding e;
       e.f(3.2);
       //e.BaseHiding::f(3.2);
       e.f(3);
}