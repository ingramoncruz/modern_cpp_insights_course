// copy constructor and copy assignment operator

#include <iostream>

class Test {
    public:
        Test() {}
        Test(const Test& t) {
            std::cout << "Copy constructor called" << std::endl;
        }
        Test& operator=(const Test& t) {
            std::cout << "Copy assignment operator called" << std::endl;
            return *this;
        }
};

int main() {
    Test t1; // default constructor
    Test t2 = t1; // copy constructor
    Test t3; // default constructor
    t3 = t1; // copy assignment operator

    return 0;
}