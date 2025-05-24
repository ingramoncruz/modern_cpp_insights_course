#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> CreateAndInsert() {
    std::vector<std::string> vec;
    vec.reserve(3); // Reserve space for 3 elements
    std::string str("Hello");
    vec.push_back(str); // Inserting a copy of string object
    // deep copy of str will be created and inserted into vec by calling a copy constructor of the string class

    vec.push_back(str+str); // Inserting a copy of an temp string object
    vec.push_back(std::move(str)); // Inserting a move of str

    return vec;
}

int main() {
    std::vector<std::string> vec = CreateAndInsert();
    for (const auto& str : vec) {
        std::cout << str << std::endl;
    }
    return 0;
}