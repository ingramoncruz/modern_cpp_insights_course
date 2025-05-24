// lvalue & rvalue

// Every expression in c++ is either lvalue or rvalue
// lvalue: An expression that has an identifiable location in memory (i.e., it has an address). 
// If you can take the address of the expression, last for extended period of time.
// rvalue: An expression that does not have an identifiable location in memory (i.e., it does not have an address).
// Cannot take the address of the expression, temp, do not exist after one line.

// lvalue reference - simple variable/object which has name and memory address, use &
//                  - appear either at left hand side or right hand side of the assignment operator

// rvalue reference - simple variable/object which has only memory address (temp obj), use &&.
//                   - appear only at right hand side of the assignment operator


#include <iostream>


int main () {
    int x = 5; // lvalue
    int y = 10; // lvalue
    int z = x + y; // z is lvalue, & (a+b) is rvalue

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "z: " << z << std::endl;

    int &p = x; // refering to lvalue(x) which is lvalue reference
    std::cout << "p: " << p << std::endl;

    int &&r = 30; // refering to rvalue(30) which is rvalue reference
    std::cout << "r: " << r << std::endl;

    // can bind from rvalue to lvalue? +> yes by binding with const
    const int &a = 20; // a is lvalue reference to rvalue(20)
    std::cout << "a: " << a << std::endl;

    return 0;
}