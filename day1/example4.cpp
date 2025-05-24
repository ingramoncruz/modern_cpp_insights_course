// reinterpret_cast - cast into anything, dangerous type of casting - high changes of crash

#include <iostream>

// most of the callback functions are implemented in C and there is no templates in C

void callback(void *p) {
    // int *tmp = p;
    int *tmp = reinterpret_cast<int*>(p); // reinterpret_cast to convert void pointer to int pointer
    std::cout << "Callback function called with value: " << *tmp << std::endl;
}

int main() {
    int a = 10;
    void *ptr = &a; // void pointer
    callback(ptr); // pass the void pointer to the callback function
    callback(reinterpret_cast<void*>(ptr)); // reinterpret_cast to convert int pointer to void pointer
    return 0;
}