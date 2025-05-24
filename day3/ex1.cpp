// is-a (inheritance), part-of (composition), has-a (aggregation)

#include <iostream>

class Account{
    std::string name;
    std::string number;
    public:
    Account() : Account(" ", " ") {} // def constructor with constructor delegation

    Account(std::string nu, std::string na) : number(nu), name(na) {} //param constructor

    Account(const Account& ref) : Account(ref.number, ref.name) {} //copy constructor with constructor delegation

    void display() {
        std::cout << "Account Number: " << number << std::endl;
        std::cout << "Account Name: " << name << std::endl;
    }
};

class Employee{
    int empid;
    std::string empmail;
    Account empacc; // part-of composition - as of now no memory // means inner object can't exist without outer object
    // when obj for Employee is created - memory for empacc is created
    public:
    Employee() : empid(0), empmail(" "), empacc() {} // def constructor with constructor delegation
    Employee(int id, std::string mail, std::string nu, std::string na) : empid(id), empmail(mail), empacc(nu, na) {} //param constructor
    void display() {
        std::cout << "Employee ID: " << empid << std::endl;
        std::cout << "Employee Mail: " << empmail << std::endl;
        empacc.display(); // call base class display
    }
};

int main() {
    Employee m1 (1001, "max@ltts.com", "123456", "Max");
    m1.display();

    return 0;
};