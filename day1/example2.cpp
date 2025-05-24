// placement new $ delete

#include <iostream>

int main () {
    int arr[100]; // alocated, used, now not needed

    int* ptr = new int [100]; // new operator

    int* parr = new(arr) int [100]; // placement new operator - RESUSE
    // instead of creating a new array, we are reusing the existing one

    delete[] ptr; // delete operator
    // delete[] parr; // placement new operator - no delete
    // does  not need delete[], since its (parr) on stack space compiler will delete when it's exits.

    return 0;
}