#pragma once

#include "Prototype.h"

class ConcretePrototype2 : public Prototype
{
public:
    ConcretePrototype2();
    ConcretePrototype2(const ConcretePrototype2& other);
    virtual ~ConcretePrototype2() {};

    virtual Prototype* Clone() const;
};

