// explicit constructor: to avoid implicit type conversion

#include <iostream>

class MyNumber {
    int number;
    public:
    // MyNumber(int value) : number(value) {}
    explicit MyNumber(int value) : number(value) {} //
    int getValue() const { return number; }
};

int main() {
    MyNumber number1(72); // direct initialization
    MyNumber number2 = MyNumber(72); // explicit constructor call

    // MyNumber number3 = 55; //Error, Implicitly converts int value 55 to MyNumber
    // MyNumber number4 = 3.14; //Error, Implicitly converts float value 3.14 to MyNumber

    MyNumber number3(static_cast<int>(55)); // direct initialization


    std::cout << "number1: " << number1.getValue() << std::endl;
    std::cout << "number2: " << number2.getValue() << std::endl;
    std::cout << "number3: " << number3.getValue() << std::endl;
    // std::cout << "number4: " << number4.getValue() << std::endl;

    return 0;
}

// when to use: constructor that takes a single arguments
// when not to use: copy & move constructors (as these do not perfom conversions)