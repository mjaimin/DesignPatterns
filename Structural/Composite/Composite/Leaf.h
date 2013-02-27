#pragma once

#include "Component.h"

class Leaf : public Component
{
public:
    Leaf();
    ~Leaf();

    virtual void Operation () {};
    virtual void Add (Component* component) {};
    virtual void Remove(Component* component) {};
    virtual Component* GetChild(int index) { return NULL;};
};

