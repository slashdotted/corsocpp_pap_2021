#include "overloading.h"

// Overloading
void fn() {

}

void fn(int x) {

}

void fn(double x) {
    
}

void fn(int x, double y) {

}

void fn(double x, int y) {
    
}


// Parametri con valore di default
int somma(int x=0, int y=0, int z=0, int k=0);

int somma(int x, int y, int z, int k) {
    return x+y+z+k;
}

void overloading() {
    somma(4);
    somma(1,2,3,4);
    somma(1,2,3);
    somma(1,2);
    fn(3.0,3);
}