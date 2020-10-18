#include <iostream>
using namespace std;
// builder is responsible for creating small parts
class IBuilder {
    public:
        virtual void buildPartA() = 0;
        virtual void buildPartB() = 0;
};

class ConcreteBuilder1 : public IBuilder {
    public:
        virtual void buildPartA() { cout << "buildPartA by ConcreteBuilder1" << endl; }
        virtual void buildPartB() { cout << "buildPartB by ConcreteBuilder1" << endl; }
};

class ConcreteBuilder2 : public IBuilder {
    public:
        virtual void buildPartA() { cout << "buildPartA by ConcreteBuilder2" << endl; }
        virtual void buildPartB() { cout << "buildPartB by ConcreteBuilder2" << endl; }
};
//director is responsible for creating product
class Director {
    private:
        IBuilder *builder;
    public:
        Director(IBuilder *obj) { builder = obj; }

        void construct()
        {
            m_builder->buildPartA();
            m_builder->buildPartB();
        }
};

int main()
{
    IBuilder *builder  = new ConcreteBuilder1();
    Director *director = new Director(builder);

    director->construct();
    return 0;
}
