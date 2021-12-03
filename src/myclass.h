template<class T, class U>
class MyClass {
public:
    T x;
    U y;

    MyClass(T v, U w) : x{v}, y{w} {};

    void printMessage() {
        cout << "x=" << typeid(x).name() << "=" << x
             << " y=" << typeid(y).name() << "=" << y
             << endl;
    };

};


template<class T, class U = int>
class MyClass2 {
public:
    T x;
    U y;

    MyClass2(T v, U w) : x{v}, y{w} {};

    void printMessage() {
        cout << "x=" << typeid(x).name() << "=" << x
             << " y=" << typeid(y).name() << "=" << y
             << endl;
    };

};

template<class U>
class MyClass2<int,U> {
public:
    int x;
    U y;

    MyClass2(int v, U w) : x{v}, y{w} {};

    void printMessage() {
        cout << "(specialization) x=" << typeid(x).name() << "=" << x
             << " y=" << typeid(y).name() << "=" << y
             << endl;
    };

};

template<>
class MyClass2<int,int> {
public:
    int x;
    int y;

    MyClass2(int v, int w) : x{v}, y{w} {};

    void printMessage() {
        cout << "(specialization) x="
             << typeid(x).name() << "=" << x
             << " y=" << typeid(y).name() << "=" << y
             << endl;
    };

};

template<class T>
class MyClass3 {
public:
    T x;

    MyClass3(T v) : x{v} {};

    void printMessage() {
        cout << "x=" << x <<
             endl;
    };

};

template<class T>
class MyClass3<T*> {
public:
    T* x;

    MyClass3(T* v) : x{v} {};

    void printMessage() {
        cout << "x=" << *x <<
             endl;
    };

};
