#include <iostream>
#include <string>
using namespace std;

class CaffeineBeverageWithHook {
public:
   //! Template method
   void prepareRecipe()
   {
      boilWater();
      brew();
      pourInCup();
      if (customerWantsCondiments())
      {
         addCondiments();
      }
      std::cout << std::endl;
   }

   //! Primitive operations
   virtual void brew()          = 0;
   virtual void addCondiments() = 0;

   virtual void boilWater() { std::cout << "Boiling water" << std::endl; }
   virtual void pourInCup() { std::cout << "Pouring into cup" << std::endl; }

   //! Hook
   virtual bool customerWantsCondiments() { return true; }
};

class TeaWithHook : public CaffeineBeverageWithHook {
public:
   void brew() { std::cout << "Steeping the tea" << std::endl; }
   void addCondiments() { std::cout << "Adding Lemon" << std::endl; }
   bool customerWantsCondiments()
   {
      return (getUserInput().compare("y") == 0)?  true : false;
   }

private:
   std::string getUserInput()
   {
      std::cout << "Would you like lemon with your tea (y/n)? ";
      return std::string("y");// Assume Random
   }
};

class CoffeeWithHook : public CaffeineBeverageWithHook {
public:
   void brew() { std::cout << "Dripping Coffee through filter" << std::endl; }
   void addCondiments() { std::cout << "Adding Sugar and Milk" << std::endl; }
   bool customerWantsCondiments()
   {
      return (getUserInput().compare("y") == 0)?  true : false;
   }

private:
   std::string getUserInput()
   {
      std::cout << "Would you like milk and sugar with your coffee (y/n)? ";
      return std::string("y");// Assume Random
   }
};

int main()
{
   CoffeeWithHook coffeeHook;
   TeaWithHook    teaHook;

   std::cout << "Making tea..." << std::endl;

   teaHook.prepareRecipe();

   std::cout << "Making coffee..." << std::endl;
   coffeeHook.prepareRecipe();

   return 0;
}
