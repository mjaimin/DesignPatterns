#include <iostream>
#include <string>

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
      std::string answer = getUserInput();

      if (answer.compare("y") == 0)
      {
         return true;
      }
      else
      {
         return false;
      }
   }

private:
   std::string getUserInput()
   {
      std::string answer;

      std::cout << "Would you like lemon with your tea (y/n)? ";
      std::cin >> answer;

      return answer;
   }
};

class CoffeeWithHook : public CaffeineBeverageWithHook {
public:
   void brew() { std::cout << "Dripping Coffee through filter" << std::endl; }
   void addCondiments() { std::cout << "Adding Sugar and Milk" << std::endl; }
   bool customerWantsCondiments()
   {
      std::string answer = getUserInput();

      if (answer.compare("y") == 0)
      {
         return true;
      }
      else
      {
         return false;
      }
   }

private:
   std::string getUserInput()
   {
      std::string answer;

      std::cout << "Would you like milk and sugar with your coffee (y/n)? ";
      std::cin >> answer;

      return answer;
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
