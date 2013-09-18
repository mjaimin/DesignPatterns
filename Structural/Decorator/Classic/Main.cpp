/*
* Adopted from http://www.cppblog.com/converse/archive/2006/07/25/10465.html
*/
#include <iostream>
using namespace std;

class Component 
{
public:
    virtual void operation() = 0;
};

class Decorator : public Component 
{
public:
    Decorator( Component* component )
        :m_component( component ) {}
protected:
    Component* m_component;
};

class ConcreteComponent : public Component 
{
public:
    virtual void operation() 
	{
        cout << "operation of ConcreteComponent" << endl;
    }
};

class ConcreteDecorator : public Decorator 
{
private:
    void addedBehavior() 
	{
        cout << "addedBehavior of ConcreteDecorator" << endl;
    }
public:
    ConcreteDecorator( Component* component )
        :Decorator( component ) { }

    virtual void operation() 
	{	
        m_component->operation();
        addedBehavior();
    }
};

int main() 
{
    Component* component = new ConcreteComponent();
    Decorator* decorator = new ConcreteDecorator( component );
	
    decorator->operation();
	
    return 0;
}