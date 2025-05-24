// cyclic dependency
// std::weak_ptr: no reference count
// if shared_ptr struck with circular dependency, use weak_ptr to break the cycle

#include <iostream>
#include <memory>

class Person {
    std::string name;
    std::weak_ptr<Person> partner;
public:
    Person(const std::string& nam) : name(nam) {
        std::cout << "Person " << name << " created.\n";
    }
    ~Person() {
        std::cout << "Person " << name << " destroyed.\n";
    }

    friend bool partnerUp(std::shared_ptr<Person> p1, std::shared_ptr<Person> p2) {
        if (!p1|| !p2) 
            return false;
        p1 -> partner = p2;
        p2 -> partner = p1;
        std::cout << p1->name << " is now partnered with " << p2->name << "\n";
        return true;
    }
};

int main() {
    auto vicky {std::make_shared<Person>("Vicky")};
    auto ricky {std::make_shared<Person>("Ricky")};
    partnerUp(vicky, ricky);

    return 0;
}

// vicky and ricky are pointing to each other, both of them will increment their reference counts
// and then will never get deleted because they are still referencing by each other

// issue with shared_ptr -> no way to break the cycle, when one object tries to be deleted,
// it will see that the object is still referencing to it, so it won't get deleted.

