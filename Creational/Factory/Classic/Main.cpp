#include <iostream>
using namespace std;
class Product
{
public:
   virtual ~Product() {}
protected:
   Product() { }
};

class ConcreteProduct : public Product
{
public:
   ConcreteProduct()
   {
      cout << "ConcreteProduct....." << endl;
   }

   ~ConcreteProduct()
   {
      cout << "~ConcreteProduct....." << endl;
   }
};


class Factory
{
public:
   ~Factory() {}
   virtual Product *CreateProduct() {}
protected:
   Factory() { }
};

class ConcreteFactory : public Factory
{
public:
   ConcreteFactory()
   {
      cout << "ConcreteFactory...." << endl;
   }

   ~ConcreteFactory()
   {
      cout << "~ConcreteFactory...." << endl;
   }

   Product *CreateProduct()
   {
      return new ConcreteProduct;
   }
};

int main(int argc, char *argv[])
{
   Factory *fac = new  ConcreteFactory();
   Product *p   = fac->CreateProduct();

   return 0;
}
