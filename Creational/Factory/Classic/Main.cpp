#include <iostream>
// Factory creates and returns product object
enum PRODUCTCODE { CONCRETEPRODUCT1,CONCRETEPRODUCT2};
using namespace std;
class Product
{
    public:
        virtual void Action(void)=0;
};

class ConcreteProduct1 : public Product
{
    public:
        void Action(void) { cout << "ConcreteProduct1....." << endl; }
};

class ConcreteProduct2 : public Product
{
    public:
        void Action(void) { cout << "ConcreteProduct2....." << endl; }
};

class Factory
{
    public:
        virtual Product *CreateProduct(PRODUCTCODE code) =0;
};

class ConcreteFactory : public Factory
{
    public:
        // Factory creates and returns product object
        Product *CreateProduct( PRODUCTCODE code )
        {
            if ( code = CONCRETEPRODUCT1 )
                return new ConcreteProduct1;
            else if ( code = CONCRETEPRODUCT2 )
                return new ConcreteProduct2;
        }
};

int main(int argc, char *argv[])
{
    Factory *f = new  ConcreteFactory();
    Product *p   = f->CreateProduct( CONCRETEPRODUCT2 );
    p->Action();

    return 0;
}
