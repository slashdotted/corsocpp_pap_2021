#include "finaldeletedefault.h"

class Base final
{
};


// Non posso specializzare / derivare
//class Derived : public Base
//{
//};

class Base2
{
public:
   virtual void f() {}
};
class Derived : public Base2
{
public:
   void f() final override {}
};

class DoubleDerived : public Derived
{
public:
   //void f() override {}
};

// ******************************************************

// Soluzione Pre-C++11
class ClasseNonCopiabile
{
private:
    ClasseNonCopiabile(const ClasseNonCopiabile&) {}
    ClasseNonCopiabile& operator=(const ClasseNonCopiabile&) {}

    ClasseNonCopiabile foo(const ClasseNonCopiabile& o) {
        ClasseNonCopiabile bar = o; // COPIA ANCORA POSSIBILE!!!!
        return bar;
    }
};

class ClasseNonCopiabile2
{
public:
    ClasseNonCopiabile2(const ClasseNonCopiabile2&) = delete;
    ClasseNonCopiabile2& operator=(const ClasseNonCopiabile2&) = delete;

    /*ClasseNonCopiabile2 foo(const ClasseNonCopiabile2& o) {
        ClasseNonCopiabile2 bar = o; // COPIA NON POSSIBILE!!!!
        return bar;
    }*/
};

// *********************************************************************

class ClasseConMetodoDefault {
public:
    ClasseConMetodoDefault(int i) {  } 
    ClasseConMetodoDefault() = default; // costruttore triviale
    
};