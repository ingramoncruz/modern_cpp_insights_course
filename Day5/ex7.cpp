// variadic template

#include <iostream>

void printEverything() {std::cout << "null\n";}

template<typename T, typename... S> 
void printEverything(T first, S... rest) {
    std::cout << first << " ";
    printEverything(rest...);
}

int main() {
    printEverything(31.95f, 1, 2.5, "Hello", 'A', 42);
    return 0;
}

// recursive function call, which happens again and again, at the end
// when no input, it goes to the base case, which is printEverything()