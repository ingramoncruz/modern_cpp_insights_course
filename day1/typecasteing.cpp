// c++ Typecasting:
// 1. static_cast
// 2. dynamic_cast
// 3. const_cast - Remove constness of the variable, heavily used in library functions.
// 4. reinterpret_cast - cast into anything, not type safe.

#include <iostream>

void libraryFunction(int *ptr) {
    // Simulate a library function that takes a pointer to const int
    std::cout << "Library function called with value: " << *ptr << std::endl;
}

int main() {
    int a =10;

    const int *ptr1 = &a; // pointer to const int
    std::cout << "Value of a: " << *ptr1 << std::endl;

    int *ptr2 = const_cast<int*>(ptr1); // error: cannot convert 'const int*' to 'int*' in assignment
    std::cout << "Value of a: " << *ptr2 << std::endl; // error: cannot dereference 'const int*'

    libraryFunction(const_cast<int*>(ptr1)); // error: cannot convert 'const int*' to 'int*' in assignment
}