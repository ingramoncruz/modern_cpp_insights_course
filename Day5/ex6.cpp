// template aliasing
#include <iostream>

// template <typename B>
template <typename B, typename S, typename X, typename Q, typename Z>
class Base {
    B x;
public:
    Base() : x(0) {std::cout << "Base constructor\n"; }
    Base(B a) : x(a) {std::cout << "Base param constructor\n"; }
    Base(const Base& b) : x(b.x) { std::cout << "Base copy constructor\n"; }

    void printX(){std::cout << x << std::endl; }
    ~Base() {std::cout << "Base destructor\n"; }
};

using Ibase = Base<int, int, int, int, int>; // template aliasing

int main() {
    Base<int, int, int, int, int> b1(10); // Base constructor
    b1.printX(); // prints 10

    Ibase b2(20); // using template aliasing
    b2.printX(); // prints 20
}