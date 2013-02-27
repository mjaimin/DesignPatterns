#pragma once

class Composite;

class Component
{
public:
    virtual ~Component();

    virtual Composite* GetComposite() {return NULL;};
    virtual void Operation () = 0;
    virtual void Add (Component* component) = 0;
    virtual void Remove(Component* component) = 0;
    virtual Component* GetChild(int index) = 0;

protected:
    Component();


};

