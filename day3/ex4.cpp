// Default controls: - destructors cannot be deleted
                  // - If object should not be copied --> delete copy constructor
                  // - when you need compiler to work --> mark as default -> shallow

#include <iostream>

class Account{
    std::string name;
    std::string number;
    public:
    Account() = default; // def constructor with constructor delegation
    Account(std::string nu, std::string na) : number(nu), name(na) {} //param constructor
    Account(const Account& ref) = delete;

    void display() { // for non const object we need non const version of display function
        std::cout << "Account Number: " << number << std::endl;
        // std::cout << "Account Name: " << name << std::endl;
    }
    void display() const { // const overloading// for const object we need const version of display function
        std::cout << "Const Account Number: " << number << std::endl;
        // std::cout << "Const Account Name: " << name << std::endl;
    }

    ~Account() = default; // destructor
};

int main() {
    Account ml("123456789", "John Doe");
    ml.display(); // non const object

    const Account* ptr = &ml; // pointer to const object
    ptr->display(); // const object

    Account m2;
    m2.display(); // non const object

    // Account m3(ml);
    // m3.display(); // non const object

}