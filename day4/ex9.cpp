// default template arguments

#include <iostream>

template <typename T=int>
class MyClass {
public:
    void print() {
    std::string t = (std::is_same<T, int>::value)? "int": ((std::is_same<T, char>::value)? "char": "unknown");
    std::cout << "T is " << t << std::endl;
    }
};

int main() {
    MyClass<char> obj1;
    MyClass myobjt; // T is defaulted to int
    myobjt.print(); // T is char
    obj1.print(); // T is int

    MyClass<std::string> mystrobj;
    mystrobj.print(); // T is unknown
}