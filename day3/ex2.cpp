// is-a (inheritance), part-of (composition), has-a (aggregation)

#include <iostream>

class Account{
    std::string name;
    std::string number;
    public:
    Account() : Account(" ", " ") {} // def constructor with constructor delegation

    Account(std::string nu, std::string na) : number(nu), name(na) {} //param constructor

    Account(const Account& ref) : Account(ref.number, ref.name) {} //copy constructor with constructor delegation

    void display() { // for non const object we need non const version of display function
        std::cout << "Account Number: " << number << std::endl;
        std::cout << "Account Name: " << name << std::endl;
    }
    void display() const { // const overloading// for const object we need const version of display function
        std::cout << "Const Account Number: " << number << std::endl;
        std::cout << "Const Account Name: " << name << std::endl;
    }
};

// class Employee{
//     int empid;
//     std::string empmail;
//     Account empacc; // part-of composition - as of now no memory // means inner object can't exist without outer object
//     // when obj for Employee is created - memory for empacc is created
//     public:
//     Employee() : empid(0), empmail(" "), empacc() {} // def constructor with constructor delegation
//     Employee(int id, std::string mail, std::string nu, std::string na) : empid(id), empmail(mail), empacc(nu, na) {} //param constructor
//     void display() {
//         std::cout << "Employee ID: " << empid << std::endl;
//         std::cout << "Employee Mail: " << empmail << std::endl;
//         empacc.display(); // call base class display
//     }
// };


class Employee{
    int empid;
    std::string empmail;
    Account* empacc; // has-a aggregation - independant memory // means inner object can exist without outer object
    public:
    Employee() : empid(0), empmail(" "), empacc(nullptr) {} // def constructor with constructor delegation
    Employee(int id, std::string mail, Account* eac) : empid(id), empmail(mail), empacc(eac) {} //param constructor
    void display() {
        std::cout << "Non const Employee ID: " << empid << std::endl;
        std::cout << "Non const Employee Mail: " << empmail << std::endl;
        empacc->display(); // call base class display
    }

    void display() const {
        std::cout << "Const Employee ID: " << empid << std::endl;
        std::cout << "Const Employee Mail: " << empmail << std::endl;
        empacc->display(); // call base class display
    }

};

int main() {

    Account ml("1001", "Max"); // non const object
    ml.display();
    
    const Account* ptr = &ml; // const object
    ptr->display();

    return 0;
};