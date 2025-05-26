// virtual function & virtual destructor

#include <iostream>

class Account {
    std::string number;
    std::string name;
public:
    Account() : number("NA"), name("NA") {}
    Account(std::string num, std::string n) : number(num), name(n) {std::cout << "base constructor\n";}
    Account(const Account& ref) = default;
    virtual void display() const {
        std::cout << "Account Number: " << number << ", Name: " << name << "\n";
    }
    virtual ~Account() {
        std::cout << "base destructor\n";
    }
};

class PrepaidAccount : public Account {
    double balance;
public:
    PrepaidAccount() : Account(), balance(0.0) {}
    PrepaidAccount(std::string num, std::string n, double bal) : Account(num, n), balance(bal) {
        std::cout << "derived constructor\n";
    }
    PrepaidAccount(const PrepaidAccount& ref) = default;
    void display() const {
        Account::display();
        std::cout << "Balance: " << balance << std::endl;
    }
    ~PrepaidAccount() {
        std::cout << "derived destructor\n";
    }
};

int main() {
    Account* acc = new PrepaidAccount("12345", "John Doe", 100.0);
    acc->display();
    delete acc; // Calls the derived destructor followed by the base destructor
    return 0;
}