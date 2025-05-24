// lambdas for UDTs

#include <iostream>
#include <vector>
#include <algorithm>

class Box {
    int l, b, h;
public:
    Box() = default;
    Box(int le, int br, int he) : l(le), b(br), h(he) {}
    Box(const Box&) = default;
    void display() {std::cout << l << "," << b << "," << h << "\n";}
    void display() const {std::cout << l << "," << b << "," << h << "\n";}
    int length() const {return l;}
    int breadth() const {return b;}
    int height() const {return h;}

};

// struct FindBoxComparator {
//     int len, bre, hei;
//     public:
//     FindBoxComparator(int l, int b, int h) : len(l), bre(b), hei(h) {}
//     bool operator()(const Box& box) const {
//         return (box.length() == len && box.breadth() == bre && box.height() == hei);
//     }
// };

int main() {
    std::vector<Box> myvec;
    myvec.emplace_back(Box(1, 2, 3));
    myvec.emplace_back(Box(4, 5, 6));
    myvec.emplace_back(Box(7, 8, 9));
    myvec.emplace_back(Box(10, 11, 12));

    // FindBoxComparator fbc(1, 2, 3);
    // auto iter = std::find_if(myvec.begin(), myvec.end(), fbc);

    int l=1, b=2, h=3;

    auto iter = std::find_if(myvec.begin(), myvec.end(), [l, b, h](const Box& box) {
        return (box.length() == l && box.breadth() == b && box.height() == h);
    });

    if (iter != myvec.end()) {
        std::cout << "Box found: ";
        iter->display();
    } else {
        std::cout << "Box not found" << std::endl;
    }

    return 0;
};