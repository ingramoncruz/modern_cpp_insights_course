// universal references
// allows a single function template to handle both lval & rval
// reducing code duplication
// Preserves the original references types, making it efficient for passing objects

#include <iostream>
#include <memory>

class Box {
    int l, b, h;
public:
    Box() = default;
    Box(int le, int br, int he) : l(le), b(br), h(he) {}
    Box(const Box&) = default;
    void display() {std::cout << l << "," << b << "," << h << "\n";}
    void display() const {std::cout << l << "," << b << "," << h << "\n";}

};

void DoSomething(const Box& lref) {
    std::cout << "lref\n";
    lref.display();
};

void DoSomething(const Box&& rref) {
    std::cout << "rref\n";
    rref.display();
};

template <typename T>
void Task(T&& ref) {
    // DoSomething(ref);  //both lvalue and rvalue references going to lvalref
    // DoSomething(std::move(ref)); //both lval & rval going to rvalref
    DoSomething(std::forward<T>(ref)); //universal reference // lval is going to lvalref and rval is going to  rvalref
}

int main() {
    Box b1(10, 20, 30);
    Task(b1);
    Task(std::move(b1));
    Task(Box(100, 200, 300)); //anonymous object

    return 0;
}
