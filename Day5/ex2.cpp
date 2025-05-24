// Reduce code bloats with non type template parameters
// 1. use single instance of the template class
// 2. use container to save the different values
// 3. use of factory function to create instance

#include <iostream>
#include <vector>

template<typename T>
class MyClass {
    T value;
    public:
    MyClass(T val) : value(val) {} // constructor to initialize value
    void print() const{
        std::cout << "Value is: " << value << std::endl;
    }
};

int main() {
    std::vector<MyClass<int>> myobj;
    myobj.push_back(MyClass<int>(42));  //passing the value 10 as a non-type template parameter
    myobj.push_back(MyClass<int>(100));
    myobj.push_back(MyClass<int>(300));

    for (const auto& obj : myobj) {
        obj.print(); // Output: Value is: 42, 100, 300
    }

    return 0;
}