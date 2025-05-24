// Name mangling 

#include <iostream>

// function overloading is enabled by name mangling
// same name, return type doesn't matter, parameters/arguments are different (type, number, mechanism)

int sum(int a, int b) {
    return a + b;
}

int sum(int a, int b, int c) {
    return a + b + c;
}

int sum(float a, float b) {
    return a + b;
}

int main() {
    int x = 10, y = 20, z = 30;
    float f1 = 10.5, f2 = 20.5;

    std::cout << "Sum of two integers: " << sum(x, y) << std::endl; // Calls sum(int, int)
    std::cout << "Sum of three integers: " << sum(x, y, z) << std::endl; // Calls sum(int, int, int)
    std::cout << "Sum of two floats: " << sum(f1, f2) << std::endl; // Calls sum(float, float)

    return 0;
}

// header -> .h -> included in the definition and main
// definition -> .cpp -> g++ - name mangling
// main -> .c -> gcc - no name mangling
