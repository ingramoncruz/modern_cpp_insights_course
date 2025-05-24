// safe and unsaef return mechanism

#include <iostream>

int gsum = 0; // global var

void swap(int a, int b) { // pass by value
    int temp = a;
    a = b;
    b = temp;
}

void swapRef(int &a, int &b) { // pass by reference
    int temp = a;
    a = b;
    b = temp;
}

void swapPtr(int *a, int *b) { // pass by pointer
    int temp = *a;
    *a = *b;
    *b = temp;
}


// int sum(int a, int b) {
//     int lsum = 0; // local var
//     // lsum = a + b; // local var
//     // return lsum;    // returning a localvar by value // safe

//     gsum = a + b; // global var
//     return gsum; // returning a global var by value //safe
// }

int *sum(int a, int b) {
    int lsum = 0; 
    // lsum = a + b; 
    // return &lsum;    // returning a localvar by address // unsafe

    gsum = a + b; // global var
    return &gsum; // returning a global var by address //safe
}

int main() {
    int x = 10, y = 20;

    int *s = sum(x, y); // s = 30
    std::cout << "Sum: " << *s << std::endl; // prints 30
    return 0;
}