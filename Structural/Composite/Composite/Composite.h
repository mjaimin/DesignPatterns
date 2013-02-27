#pragma once

#include "Component.h"
#include <vector>

class Composite : public Component
{
public:
    Composite();
    ~Composite();

    virtual Composite* GetComposite();
    virtual void Operation ();
    virtual void Add (Component* component);
    virtual void Remove(Component* component);
    virtual Component* GetChild(int index);

private:
    std::vector<Component*> composite;
};

