#include <iostream>
#include <typeinfo>

// Una classe template può avere più tipi generici
template<class T, class U>
class MyClass {
public:
    T x;
    U y;

    MyClass(T v, U w) : x{v}, y{w} {};

    void printMessage() {
        std::cout << "x=" << typeid(x).name() << "=" << x
             << " y=" << typeid(y).name() << "=" << y
             << x+y << std::endl;
    };

};

// posso indicare un tipo predefinito
template<class T, class U = int>
class MyClass2 {
public:
    T x;
    U y;

    MyClass2(T v, U w) : x{v}, y{w} {};

    void printMessage() {
        std::cout << "x=" << typeid(x).name() << "=" << x
             << " y=" << typeid(y).name() << "=" << y
             << x+y << std::endl;
    };

};

// posso indicare entrambi i tipi con un valore predefinito
template<class T = int, class U = int>
class MyClass2b {
public:
    T x;
    U y;

    MyClass2b(T v, U w) : x{v}, y{w} {};

    void printMessage() {
        std::cout << "x=" << typeid(x).name() << "=" << x
             << " y=" << typeid(y).name() << "=" << y
            << x+y << std::endl;
    };

};

// Specializzazione parziale (quando U è std::string)
template<class T>
class MyClass2<T,std::string> {
public:
    T x;
    std::string y;

    MyClass2(T v, const std::string& w) : x{v}, y{w} {};

    void printMessage() {
        std::cout << "Specializzazione parziale (quando U è std::string) x=" << typeid(x).name() << "=" << x
             << " y=" << typeid(y).name() << "=" << y
             << std::endl;
    };

};

// Specializzazione parziale (quando T è std::string)
template<class U>
class MyClass2<std::string, U> {
public:
    std::string x;
    U y;

    MyClass2(const std::string& v, U w) : x{v}, y{w} {};

    void printMessage() {
        std::cout << "Specializzazione parziale (quando T è std::string) x=" << typeid(x).name() << "=" << x
             << " y=" << typeid(y).name() << "=" << y
             << std::endl;
    };
};

// Specializzazione totale (quando T e U sono std::string)
template<>
class MyClass2<std::string, std::string> {
public:
    std::string x;
    std::string y;

    MyClass2(const std::string& v, const std::string& w) : x{v}, y{w} {};

    void printMessage() {
        std::cout << "Specializzazione totale (quando T e U sono std::string) x=" << typeid(x).name() << "=" << x
             << " y=" << typeid(y).name() << "=" << y
             << x+y << std::endl;
    };
};

// Classe "generica", con T generico
template<class T>
class MyClass3 {
public:
    T x;

    MyClass3(T v) : x{v} {};

    void printMessage() {
        std::cout << "x=" << x << std::endl;
    };

};

// Classe "generica", con T di tipo puntatore
template<class T>
class MyClass3<T*> {
public:
    T* x;

    MyClass3(T* v) : x{v} {};

    void printMessage() {
        std::cout << "x=" << *x << std::endl;
    };

};
