#include <iostream>
#include <string>
class IVisitor{
    public:
void IVisitor::Visit();
}

class IElement
{
public:
   std::string Name;
   virtual void Accept(IVisitor v) = 0;
};

class Household : public IElement
{
public: Household(std::string name)
   {
      Name = name;
   }

   void Accept(IVisitor* v)
   {
      v->Visit(this);
   }
};

class BusinessEntity : public IElement
{
public:
   BusinessEntity(std::string name)
   {
      Name = name;
   }

   void Accept(IVisitor v)
   {
      v->Visit(this);
   }
};

public IVisitor
{
public:
   virtual void Visit(IElement * e) = 0;
};

class SantaClaus : public IVisitor
{
public:
   void Visit(IElement *v)
   {
      std::cout << "Santa visited " << v->Name << std::endl;
   }
};

class MailCarrier : public IVisitor
{
public:
   void Visit(IElement *v)
   {
      std::cout << "MailCarrier visited " << v->Name << std::endl;
   }
};

int main()
{
   //first set up the structure
   IElement *household1      = new Household("The Adams Family");
   IElement *household2      = new Household("The Jones Family");
   IVisitor *BusinessEntity1 = new BusinessEntity("The Oatmeal Bakery");
   IVisitor *BusinessEntity2 = new BusinessEntity("The Ice Cream Shop");

   //use one visitor, or logic
   IVisitor *visitor = new SantaClaus();

   household1.Accept(visitor);
   household2.Accept(visitor);
   BusinessEntity1.Accept(visitor);
   BusinessEntity2.Accept(visitor);

   i.Accept(visitor);          //apply the logic to the element
   //use another visitor, or logic
   visitor = new MailCarrier();
   household1.Accept(visitor);
   household2.Accept(visitor);
   BusinessEntity1.Accept(visitor);
   BusinessEntity2.Accept(visitor);
}
