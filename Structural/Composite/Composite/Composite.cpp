#include "stdafx.h"
#include "Composite.h"


Composite::Composite():
    composite()
{
}


Composite::~Composite()
{
    composite.clear();
}

Composite* Composite::GetComposite()
{
    return this;
}

void Composite::Operation ()
{
    for (auto it = composite.begin(); it != composite.end(); it++)
    {
        (*it)->Operation();
    }
}

void Composite::Add (Component* component)
{
    composite.push_back(component);
}

void Composite::Remove(Component* component)
{
    for (auto it = composite.begin(); it != composite.end(); it++)
    {
        if (*it == component)
        {
            composite.erase(it);
            break;
        }
    }
}

Component* Composite::GetChild(int index)
{
    std::vector<Component*>::iterator it = composite.begin() + index;
    return *it;
}