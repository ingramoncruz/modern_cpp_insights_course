//lambda with STL

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> myvec{1,8,5,6,1,10,3,9,4,7};

    std::sort(myvec.begin(), myvec.end(), [](int a, int b) {
        return a < b; // sort in descending order
    });
    for (auto i : myvec) 
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}