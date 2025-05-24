// cyclic dependency between mother, son & daughter, use weak_ptr to break it
#include <iostream>
#include<memory>

class Son;
class Daughter;
class Mother {
public:
    Mother() {
        std::cout << "Mother constructor called" << std::endl;
    }
    ~Mother() {
        std::cout << "Mother destructor called" << std::endl;
    }

    void setSon(std::weak_ptr<Son> son) {
        mySon = son;
    }
    void setDaughter(std::weak_ptr<Daughter> daughter) {
        myDaughter = daughter;
    }

    std::weak_ptr<Son> mySon;
    std::weak_ptr<Daughter> myDaughter;

    // Mother doesn't increase the reference count for son and daughter
    // when the last shared_ptr dissapears, allows obj to be deleted
};

class Son {
    public:
    std::shared_ptr<Mother> myMother;
    Son(std::shared_ptr<Mother> mother) : myMother(mother) {
        std::cout << "Son constructor called" << std::endl;
    }
    ~Son() {
        std::cout << "Son destructor called" << std::endl;
    }
};

class Daughter {
public:
    std::shared_ptr<Mother> myMother;
    Daughter() {
        std::cout << "Daughter constructor called" << std::endl;
    }
    ~Daughter() {
        std::cout << "Daughter destructor called" << std::endl;
    }
    Daughter(std::shared_ptr<Mother> mother) {
        myMother = mother;
    }
};

int main() {
    std::shared_ptr<Mother> mother = std::shared_ptr<Mother>(new Mother());
    std::shared_ptr<Son> son = std::shared_ptr<Son>(new Son(mother));
    // 1 shared_ptr is dependen on the other shared_ptr so there is a cyclic dependency
    // in order to break it use weak_ptr
    std::shared_ptr<Daughter> daughter = std::shared_ptr<Daughter>(new Daughter(mother));

    mother->setSon(son);
    mother->setDaughter(daughter);

    std::cout << mother.use_count() << std::endl; // 3
    std::cout << son.use_count() << std::endl; // 2
    std::cout << daughter.use_count() << std::endl; // 2
    return 0;
}