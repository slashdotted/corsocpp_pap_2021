#ifndef MyList2_H
#define MyList2_H

#include <stdexcept>
#include <iostream>

template<typename T, int Size>
class MyList2 {
public:
    explicit MyList2();
    MyList2(const MyList2<T,Size>& o) = delete;
    MyList2(const MyList2<T,Size>&& o) = delete;
    MyList2<T,Size>& operator=(const MyList2<T,Size>& o) = delete;
    MyList2<T,Size>& operator=(const MyList2<T,Size>&& o) = delete;
    ~MyList2();

    T& operator[](int i);
    const T& operator[](int i) const;
    int size() const;
private:
    T* m_array;
};

template<typename T, int Size>
MyList2<T, Size>::MyList2()
{
    if (Size <= 0) {
        throw std::out_of_range("Invalid size");
    }
    m_array = new T[Size];
}

template<typename T, int Size>
const T& MyList2<T, Size>::operator[](int i) const
{
    if (i < 0 || i >= Size) {
        throw std::out_of_range("Invalid index");
    }
    return m_array[i];
}

template<typename T, int Size>
T& MyList2<T, Size>::operator[](int i)
{
    if (i < 0 || i >= Size) {
        throw std::out_of_range("Invalid index");
    }
    return m_array[i];
}

template<typename T, int Size>
int MyList2<T, Size>::size() const
{
    return Size;
}

template<typename T, int Size>
MyList2<T, Size>::~MyList2() {
    delete[] m_array;
}

#endif