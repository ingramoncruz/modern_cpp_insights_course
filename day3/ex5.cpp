// Inclass initializers

#include <iostream>

class Box {
    int l{10}, b{20}, h{30};
    public:
    Box() = default; 
    Box(int l, int b, int h) : l(l), b(b), h(h) {} 
    Box(const Box&) = default; // copy constructor
    Box& operator=(const Box&) = default; // copy assignment operator

    void display() {
        std::cout << "Length: " << l << std::endl;
        std::cout << "Breadth: " << b << std::endl;
        std::cout << "Height: " << h << std::endl;
    }

    void display() const {
        std::cout << "Const Length: " << l << std::endl;
        std::cout << "Const Breadth: " << b << std::endl;
        std::cout << "Const Height: " << h << std::endl;
    }
    int length() const { return l; }
    int breadth() const { return b; }
    int height() const { return h; }

    Box getBox() { return *this; }
    Box returnBox() { return {10, 20, 30}; } // uniform initialization
};

class Shipment {
    Box b1{10, 20, 30}, b2{20, 30, 40}, b3{30, 40, 50}, b4{40, 50, 60};
    // in class initialization can be used in composition
    public:
    //constructors

};

int main() {
    return 0;
}