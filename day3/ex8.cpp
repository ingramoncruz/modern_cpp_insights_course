// internal implementation of the unique_ptr class

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

template <typename T>
class MyUniquePtr {
    T* ptr;
    public:
    MyUniquePtr() : ptr(nullptr) {} // constructor
    MyUniquePtr(T* p) : ptr(p) {} // constructor
    MyUniquePtr(const MyUniquePtr&) = delete; // copy constructor // copy semantics
    MyUniquePtr& operator=(const MyUniquePtr&) = delete; // copy assignment operator

    // move semantics
    MyUniquePtr(MyUniquePtr&& other) { // move constructor
        ptr = other.ptr; // transfer ownership
        other.ptr = nullptr; // transfer ownership
    }

    MyUniquePtr& operator=(MyUniquePtr&& other) { // move assignment operator
        if (this == &other) { return *this; } // self assignment check
        ptr = other.ptr; // transfer ownership
        other.ptr = nullptr; // transfer ownership
        return *this;
    }

    ~MyUniquePtr() { // destructor
        delete ptr; // release memory
    }

    T* get() { return ptr; } // get pointer -> return the value of the ptr member

    T* operator->() { return ptr; } // arrow operator - returns a pointer to the object being managed (using the pointer member)
    T& operator*() { return *ptr; } // dereference operator - returns a reference to the object being managed (using the pointer member)

    void swap(MyUniquePtr& other) { // swap function
        T * temp = ptr; // temporary pointer
        ptr = other.ptr; // transfer ownership
        other.ptr = temp; // transfer ownership
    }

    T* release() { // return the value of the ptr member, and sets to nullptr
        T* temp = ptr; // temporary pointer
        ptr = nullptr; // transfer ownership
        return temp; // return the pointer
    }

    void reset(T* p) { // reset function
        if (ptr != nullptr) { delete ptr; } 
        ptr = p; // transfer ownership
    }
};

int main() {


    MyUniquePtr<Box> aptr1 (new Box(100, 200, 300)); 
    aptr1->display();
    // MyUniquePtr<Box> aptr2 (aptr1); // copy constructor call // error -> use of deleted function
    // MyUniquePtr<Box> aptr3;
    // aptr3 = aptr1; // copy assignment operator // error -> use of deleted function

    MyUniquePtr<Box> aptr4 (std::move(aptr1)); // move constructor call
    aptr4->display();
    // aptr1->display(); // error: dangling pointer (segmentation fault)

    MyUniquePtr<Box> aptr5;
    aptr5 = std::move(aptr4); // move assignment operator
    aptr5->display();

    MyUniquePtr<Box> aptr6 (new Box(10, 20, 30));
    std::cout << aptr5.get() << std::endl;
    std::cout << aptr6.get() << std::endl;

    aptr5.swap(aptr6); // swap function
    std::cout << aptr5.get() << std::endl;
    std::cout << aptr6.get() << std::endl;

    aptr5->display();
    aptr6->display();

    return 0;
};
//