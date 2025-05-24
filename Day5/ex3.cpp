// template specialization: for one data type, template function must act differently

#include <iostream>

template <typename T>
void print(T x, T y) {
    std::cout << "no specialization\n";
    std::cout << x << ", " << y << std::endl;
}

// template specialization 
template <>
void print<float>(float x, float y) {
    std::cout << "float specialization\n";
    std::cout << x << ", " << y << std::endl;
}

template <>
void print<char>(char x, char y) {
    std::cout << "char specialization\n";
    std::cout << x << ", " << y << std::endl;
}


int main() {
    print(10, 20);
    print(10.5f, 20.5f);
    print('x', 'y');

    return 0;
}
