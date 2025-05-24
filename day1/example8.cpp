// range base for loop
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{10, 20, 30, 40, 50};

    std::vector<int>::iterator it; // iterators - looping
    for (it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    for(auto elm : vec) { // range-based for loop
        std::cout << elm << " ";
    }
    std::cout << std::endl;

    return 0;
}