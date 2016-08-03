#include <iostream>
using namespace std;

class Target {
public:
   virtual void newRequest() { cout << "Target's new request..." << endl; }
};

class Adaptee {
public:
   void SpecificRequest() { cout << "I do work specific way..." << endl; }
};

class Adapter : public Target, private Adaptee {
private:
   Adaptee *adaptee;
public:
   Adapter(Adaptee *obj) : adaptee(obj) {}
   void newRequest() { adaptee->SpecificRequest(); }
};

int main()
{
   Adaptee *adaptee = new Adaptee();
   Target  *target  = new Adapter(adaptee);

   target->newRequest();

   delete target;
   delete adaptee;

   return 0;
}
