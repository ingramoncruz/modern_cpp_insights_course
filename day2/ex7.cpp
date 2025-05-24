// initializer list with constructors, construcor delegation

#include <iostream>

class Account {
    std::string name;
    std::string number;
    public:
    // Account() : number(" "), name(" ") {} //def constructor
    Account() : Account(" ", " ") {} // def constructor with constructor delegation

    Account(std::string nu, std::string na) : number(nu), name(na) {} //param constructor

    // Account(const Account& ref) : number(ref.number), name(ref.name) {} //copy constructor
    Account(const Account& ref) : Account(ref.number, ref.name) {} //copy constructor with constructor delegation

    void display() {
        std::cout << "Account Number: " << number << std::endl;
        std::cout << "Account Name: " << name << std::endl;
    }
};

class PrepaidAccount : public Account {
    double balance;
    public:
    PrepaidAccount() : Account(), balance(0) {} //constructor delegation from derived class to base class
    PrepaidAccount(std::string nu, std::string na, double bal) : Account(nu, na), balance(bal) {} //constructor delegation from derived class to base class
    PrepaidAccount(const PrepaidAccount& ref) : Account(ref), balance(ref.balance) {} //copy constructor

    void display() {
        Account::display(); // call base class display
        std::cout << "Balance: " << balance << std::endl;
    }
};

int main() {
    PrepaidAccount p1("11111", "John Doe", 1000);
    p1.display();

    return 0;
}

