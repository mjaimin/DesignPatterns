#include "ConcretePrototype2.h"
#include <iostream>


ConcretePrototype2::ConcretePrototype2() 
{
    std::cout << "default Constructor" << std::endl;
};

ConcretePrototype2::ConcretePrototype2(const ConcretePrototype2& other)
{
    std::cout << "Copy Constructor" << std::endl;
};

Prototype* ConcretePrototype2::Clone() const
{
    return new ConcretePrototype2(*this);
}