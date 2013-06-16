#include "ConcretePrototype1.h"
#include <iostream>


ConcretePrototype1::ConcretePrototype1() 
{
	std::cout << "default Constructor" << std::endl;
};

ConcretePrototype1::ConcretePrototype1(const ConcretePrototype1& other)
{
	std::cout << "Copy Constructor" << std::endl;
};

Prototype* ConcretePrototype1::Clone() const
{
	return new ConcretePrototype1(*this);
}