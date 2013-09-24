#include <iostream>
using namespace std;

class Implementor {
  public:
    virtual void operationImpl() = 0;
};

class Abstraction {
  protected:
    Implementor* m_implementor;
  public:
    Abstraction( Implementor* implementor ) :m_implementor( implementor ) { }
    void operation() { m_implementor->operationImpl(); }
};

class ConcreteImplementorA : public Implementor {
  public:
    virtual void operationImpl() { cout << "Implementation by ConcreteImplementorA" << endl; }
};

class ConcreteImplementorB : public Implementor {
  public:
    virtual void operationImpl() { cout << "Implementation by ConcreteImplementorB" << endl; }
};

int main() {

  ConcreteImplementorA* implementorA = new ConcreteImplementorA();
  Abstraction* abstraction1 = new Abstraction( implementorA );
  abstraction1->operation();

  ConcreteImplementorB* implementorB = new ConcreteImplementorB();
  Abstraction* abstraction2 = new Abstraction( implementorB );
  abstraction2->operation();

  return 0;
}
