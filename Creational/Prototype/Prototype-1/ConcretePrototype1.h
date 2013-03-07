#pragma once

#include "Prototype.h"

class ConcretePrototype1 : public Prototype
{
public:
    ConcretePrototype1();
    ConcretePrototype1(const ConcretePrototype1& other);
    virtual ~ConcretePrototype1() {};

    virtual Prototype* Clone() const;
};

