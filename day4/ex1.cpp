// shared_ptr
// it keeps a reference count to maintain how many shared_ptr are pointing to the same object
// use count
// allows shared/multiple ownership, allows copy&move semantics, no memory leak

#include <iostream>
#include <memory>

class Box {
    int l, b, h;
    public:
    Box() : l(0), b(0), h(0) {} // default constructor
    Box(int l, int b, int h) : l(l), b(b), h(h) {} 
    Box(const Box&) = default; // copy constructor
    Box& operator=(const Box&) = default; // copy assignment operator

    void setLength(int length) { l = length; }
    int getLength() { return l; }

    void display() {
        std::cout << "Length: " << l << std::endl;
        std::cout << "Breadth: " << b << std::endl;
        std::cout << "Height: " << h << std::endl;
    }

};

int main () {
    std::shared_ptr<Box> sptr1(new Box(50, 70, 100)); 
    std::cout << sptr1.use_count() << std::endl; 
    sptr1->display();

    std::shared_ptr<Box> sptr2(sptr1); // copy constructor
    std::cout << sptr1.use_count() << std::endl;
    std::cout << sptr2.use_count() << std::endl;
    sptr2->display();

    std::shared_ptr<Box> sptr3 = sptr1; // copy assignment operator
    std::cout << sptr1.use_count() << std::endl;
    std::cout << sptr3.use_count() << std::endl;

    std::shared_ptr<Box> sptr5(std::move(sptr1)); // move constructor
    std::cout << sptr5.use_count() << std::endl;
    std::cout << sptr1.use_count() << std::endl; // sptr1 is now null

    std::cout << sptr5.get() << std::endl; // sptr5 is now pointing to the same object as sptr1
    std::cout << sptr1.get() << std::endl; // sptr1 is now null
    




    return 0;
}