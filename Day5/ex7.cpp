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

//nested template / right angle parenthesis
/*
Before C++11
std::vector<int> myvec;
std::unique_ptr<int> uptr;
// before c++!1 we used to write like this
std::vector<std::unique_ptr<int>    > myvec2; // this is not allowed in C++11
// After C++11 
std::vector<std::unique_ptr<int>> myvec2; // this is allowed in C++11 and later
// This is called "right angle bracket problem" or "diamond problem" in C++
// nested templates/right angle parenthesis


*/