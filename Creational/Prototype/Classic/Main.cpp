#include <iostream>
#include <string>

/* Prototype base class. */
class Prototype {
    public:
        int value;
        virtual Prototype *clone() = 0;
};

class ConcretePrototype1 : public Prototype
{
    public:
        ConcretePrototype1(int i) { value = i; }
        ConcretePrototype1(const ConcretePrototype1& cp) { this->value = cp.value; }
        Prototype *clone() { return new ConcretePrototype1(*this); }
};

class ConcretePrototype2 : public Prototype
{
    public:
        ConcretePrototype2(int i) { value = i; }
        ConcretePrototype2(const ConcretePrototype2& cp) { this->value = cp.value; }
        Prototype *clone() { return new ConcretePrototype2(*this); }
};

int main()
{
    Prototype *prototype1 = new ConcretePrototype1(5);
    Prototype *object     = prototype1->clone();
    std::cout << object->value << std::endl;

    /* All the object were created by cloning the prototypes. */

    delete object;
    delete prototype1;

    return 0;
}
