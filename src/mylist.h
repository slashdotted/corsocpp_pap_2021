#ifndef MYLIST_H
#define MYLIST_H

#include <stdexcept>
#include <iostream>

template<typename T>
class MyList {
public:
    explicit MyList(int size);
    MyList(const MyList<T>& o) = delete;
    MyList(const MyList<T>&& o) = delete;
    MyList<T>& operator=(const MyList<T>& o) = delete;
    MyList<T>& operator=(const MyList<T>&& o) = delete;
    ~MyList();

    T& operator[](int i);
    const T& operator[](int i) const;
    int size() const;
private:
    T* m_array;
    int m_size;
};

template<typename T>
MyList<T>::MyList(int size)
{
    if (size <= 0) {
        throw std::out_of_range("Invalid size");
    }
    m_array = new T[size];
    m_size = size;
}

template<typename T>
const T& MyList<T>::operator[](int i) const
{
    if (i < 0 || i >= m_size) {
        throw std::out_of_range("Invalid index");
    }
    return m_array[i];
}

template<typename T>
T& MyList<T>::operator[](int i)
{
    if (i < 0 || i >= m_size) {
        throw std::out_of_range("Invalid index");
    }
    return m_array[i];
}

template<typename T>
int MyList<T>::size() const
{
    return m_size;
}

template<typename T>
MyList<T>::~MyList() {
    delete[] m_array;
}

#endif