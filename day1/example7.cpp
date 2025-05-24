// decltype: It checks the declared type of expression

#include <iostream>

template <typename T1, typename T2>
// T2 add(T1 a, T2 b) {
//     return a + b;
// }
// Output:
// Result: 8.14
// Type of result: 8

auto add(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
}

// Output:
// Result: 8.14
// Type of result: 8.14

int main() {
    int x = 5;
    double y = 3.14;
    std::cout << "Result: " << add(x, y) << std::endl;
    std::cout << "Type of result: " << add(y, x) << std::endl;



    // // Using decltype to deduce the type of a variable
    // decltype(result) z = 10.0; // z is of type double
    // std::cout << "z: " << z << std::endl;

    return 0;
}