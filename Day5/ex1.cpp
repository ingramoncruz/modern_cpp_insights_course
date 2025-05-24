// non type template parameters
// are values that can be passed as template parameters, which are non types
// These values cn anything like int, float, enum, pointers, reference 
// even any other non type template parameters

#include <iostream>

template<int value>
class MyClass {
    public:
    void print() {
        std::cout << "Value is: " << value << std::endl;
    }
};

int main() {
    MyClass<42> obj1;  //passing the value 10 as a non-type template parameter
    MyClass<100> obj2;
    MyClass<300> obj3;

    // creating three separate instance of the class in the memory
    // each instance has its own copy of the var value, means three times the memory
    // code bloats with non type template parameters
    
    obj1.print(); // Output: Value is: 42
    obj2.print(); // Output: Value is: 100
    obj3.print(); // Output: Value is: 300

    return 0;
}