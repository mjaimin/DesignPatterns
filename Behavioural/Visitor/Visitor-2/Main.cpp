#include <iostream>
using namespace std;

class Operation;

class Animal {
public:
   virtual void letsDo(Operation *op) = 0;
};

class Cat;
class Dog;

class Operation {
public:
   virtual void catOperation(Cat *cat) = 0;
   virtual void dogOperation(Dog *dog) = 0;
};

class Sound : public Operation {
public:
   void dogOperation(Dog *dog)
   {
      cout << "woof!" << endl;
   }

   void catOperation(Cat *cat)
   {
      cout << "meow!" << endl;
   }
};

class Print3D : public Operation {
public:
   void dogOperation(Dog *dog)
   {
      cout << "In Dog Format!" << endl;
   }

   void catOperation(Cat *cat)
   {
      cout << "In Cat Format!" << endl;
   }
};


class Dog : public Animal {
public:
   void letsDo(Operation *op)
   {
      op->dogOperation(this);
   }
};

class Cat : public Animal {
public:
   void letsDo(Operation *op)
   {
      op->catOperation(this);
   }
};

int main()
{
   Cat     *cat     = new Cat();
   Sound   *sound   = new Sound();
   Print3D *print3D = new Print3D();

   cat->letsDo(print3D);
   cat->letsDo(sound);

   return 0;
}
