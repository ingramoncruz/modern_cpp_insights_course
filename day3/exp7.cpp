// std::unique_ptr

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

int main() {

    std::unique_ptr<int> aptr1 (new int(10)); 
    std::cout << *aptr1 << std::endl;

    std::unique_ptr<Box> aptr2 (new Box(10, 20, 30)); 
    aptr2->display();

    std::unique_ptr<Box> aptr3;
    // aptr3 = aptr2; // copy assignment operator operator= //use of deleted function 
    aptr3 = std::move(aptr2);
    aptr3->display();
    // aptr2->display(); // error: dangling pointer, owner of the object is aptr3, that is the reason auto_ptr is deprecated
    // why? -> passing nullptr to func






    // std::unique_ptr<Box> aptr4 (aptr3); //copy constructor call -> use of deleted function
    std::unique_ptr<Box> aptr4(std::move(aptr3)); // move assignment operator
    aptr4->display();
    // // aptr3->display(); // error: dangling pointer (segmentation fault)
    // // owner of the object is aptr4, that is the reason auto_ptr is deprecated

    return 0;
}