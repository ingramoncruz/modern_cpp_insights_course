// deriving

#include <iostream>

template<typename B>
class Base {
    B x;
public:
    Base() : x(0) {std::cout << "Base constructor\n"; }
    Base(B a) : x(a) {std::cout << "Base param constructor\n"; }
    Base(const Base& b) : x(b.x) { std::cout << "Base copy constructor\n"; }

    void printX(){std::cout << x << std::endl; }
    ~Base() {std::cout << "Base destructor\n"; }
};

template<typename D>
class Derived : public Base<D> {
    D y;
public:
    // Derived():Base<D>::Base(), y(0) { std::cout << "Derived constructor\n"; }
    Derived() : Base<D>(), y(0) {std::cout << "Derived constructor\n"; }
    // Derived(D a) : Base<D>(a), y(a) {std::cout << "Derived param constructor\n"; }
    Derived(D a, D b) : Base<D>::Base(a), y(b) { std::cout << "Derived param constructor\n"; }
    Derived(const Derived& ref) : Base<D>::Base(ref), y(ref.y) { std::cout << "Derived copy constructor\n"; }

    void printXY() {
        Base<D>::printX();
        std::cout << y << std::endl;
    }

    ~Derived() { std::cout << "Derived destructor\n"; }
};

int main() {
    Derived<int> d1(10, 20);
    d1.printXY();

    return 0;
}