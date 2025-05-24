// lambdas: are substited for single time callback functions
// Advantages: reduces code footprint, reduces the control overhead, reduces data transfer
// [](){} -> [captured syntax], (parameters), {body}

#include <iostream>

int Task(int x, int y, int(*fptr)(int, int)) {
    int tmp = fptr(x, y);
    return tmp;
}

// int add(int x, int y) {
//     return x + y;
// }
// int multiply(int x, int y) {
//     return x * y;
// }

int main() {
    // int resl = Task(10, 20, add);
    int resl = Task(10, 20, [](int a, int b){return a + b;}); // lambda function
    std::cout << "add: " << resl << std::endl;
    // int res2 = Task(10, 20, multiply);
    int res2 = Task(10, 20, [](int a, int b){return a * b;}); // lambda function
    std::cout << "multiply: " << res2 << std::endl;

    return 0;
}