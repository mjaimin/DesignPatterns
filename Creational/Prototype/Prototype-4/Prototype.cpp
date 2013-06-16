class Prototype {
public:
    virtual ~Prototype() {}
    virtual Prototype* clone() const = 0;
};
 
// the product that we want to clone
class Human : public Prototype {
public:
    // constructors
    Human(const unsigned int initAge) : age(initAge) {}
    Human(const Human &h) {
        age = h.age;
    }
 
    // destructor
    ~Human() {}
 
    unsigned int getAge() const {
        return age;
    }
 
    // clone method
    Prototype* clone() const {
        return new Human(*this);
    }
 
private:
    unsigned int age;
};
 
int main() {
    Human *mark = new Human(5);
    std::cout << "mark's age is " << mark->getAge() << std::endl;
    Human *mark2 = (Human*)mark->clone();
    std::cout << "mark2's age is " << mark2->getAge() << std::endl;
    return 0;
}