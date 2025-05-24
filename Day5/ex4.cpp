// normal function oveloading: same name, return type doesn't matter
// different parameters (datatype, number of parameters, mechanism)

//template function overloading: same name, return type doesn't matter
// different parameters (number of parameters, mechanism)

#include <iostream>

template <typename S>
void swap(S &x, S &y) {
    std::cout << "by refer\n";
    S temp = x;
    x = y;
    y = temp;
}

// by value and by reference cannot be overloaded -> function call will be same/ambiguous

template <typename S>
void swap(S *x, S *y) {
    std::cout << "by address\n";
    S temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 10, b = 20;
    // swap<int>(a, b);
    swap<int>(&a, &b); 
    std::cout << "a: " << a << ", b: " << b << std::endl;
    
    return 0;
}