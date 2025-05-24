// constexpr - runtime optimization

#include <iostream>
#define Macro 10; // preprocessor resolved
constexpr int add(int a, int b) {
    return a + b;
}

int main() {
    constexpr int x = 5;
    constexpr int y = z; // compile time resolved - execution/runtime optimization
    constexpr int result = add(x, y); // compile time resolved

    return 0;
}