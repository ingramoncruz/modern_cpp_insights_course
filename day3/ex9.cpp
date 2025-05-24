// std::make_unique(C++14)
// used to create a unique_ptr objtect, helps to allocate memory for an object & transfer ownership to a unique_ptr


#include <iostream>
#include <memory>

class Sample {
    int x;
public:
    Sample(int i) : x(i) {}
    int getX() const { return x; }
    ~Sample() {
        std::cout << "Sample destructor called" << std::endl;
    }
};

int main() {
    Sample* ptr = new Sample(10);
    std::unique_ptr<Sample> p0(ptr); // avoid this method because single ptr can be pointed to multiple unique_ptr
    // std::unique_ptr<Sample> p1(ptr);
    // or
    std::unique_ptr<Sample> p1(new Sample(20)); // no exception safety
    // or
    std::unique_ptr<Sample> p2 = std::make_unique<Sample>(30); // exception safe
    // make_fubction will handle if there is any exception

    std::unique_ptr<Sample> p3 = std::move(p1); // transfer ownership

    std::cout << "p0: " << p0->getX() << std::endl;
    // std::cout << "p1: " << p1->getX() << std::endl;
    std::cout << "p2: " << p2->getX() << std::endl;
    std::cout << "p3: " << p3->getX() << std::endl;

    return 0;
}
// Sample destructor called