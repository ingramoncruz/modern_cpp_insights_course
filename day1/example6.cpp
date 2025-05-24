// auto it is used for type deduction
// it is not a data type, rather its like a substitue pillar
// ausse -> assume datatype according to the scenario

#include <iostream>
#include<typeinfo>

class Base {};

int main() {
    // auto - type deduction
    auto x = 5; // int
    auto y = 3.14; // double
    auto z = "Hello"; // const char*
    auto b = Base(); // Base
    auto c = new Base(); // Base*

    std::cout << "Type of x: " << typeid(x).name() << std::endl;
    std::cout << "Type of y: " << typeid(y).name() << std::endl;
    std::cout << "Type of z: " << typeid(z).name() << std::endl;
    std::cout << "Type of b: " << typeid(b).name() << std::endl;
    std::cout << "Type of c: " << typeid(c).name() << std::endl;

    return 0;
}