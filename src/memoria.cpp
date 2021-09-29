#include "memoria.h"

struct MioTipo {
};

void foo_alla_java() {
    auto* t{new MioTipo};
    // lavoro con *t
    delete t;
}

void foo_alla_cpp() {
    MioTipo t;
    // lavoro con t
}

void memoria() {
    // Allocazione
    int* i{new int};
    int* j{new int{13}};
    int* arr{new int[10]};

    // Delete
    delete i;
    delete j;
    delete[] arr;
}