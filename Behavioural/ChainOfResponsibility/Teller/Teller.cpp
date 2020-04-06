#include <iostream>

using std::cout; using std::endl; using std::cin;

class Administrator {
private:
   Administrator *successor_;
public:
   Administrator(Administrator *successor=nullptr):successor_(successor){} 
   virtual void handleRequest (int amount) {
      if (successor_ != nullptr)
	 successor_ -> handleRequest(amount);
   }
};

// derived classes
class Teller: public Administrator{
public:
   Teller(Administrator *successor=nullptr):
                     Administrator(successor){}
   void handleRequest (int amount) override {
      if (amount < 500)
	 cout << "Teller approves request for " << amount << endl;
      else
	 Administrator::handleRequest(amount);
   }
};

class Manager: public Administrator{
public:
   Manager(Administrator *successor=nullptr):
      Administrator(successor){}
   void handleRequest (int amount) override {
      if (amount < 1000)
	 cout << "Manager approves request for " << amount << endl;
      else
	 Administrator::handleRequest(amount);
   }
};

class Finance: public Administrator{
public:
   Finance(Administrator *successor=nullptr):
      Administrator(successor){}
   void handleRequest (int amount) override {
      if (amount < 5000)
	 cout << "Finance approves request for " << amount << endl;
      else
	 Administrator::handleRequest(amount);
   }
};


// derived classes
class President: public Administrator{
public:
   President(Administrator *successor=nullptr):
      Administrator(successor){}
   void handleRequest (int amount) override {
      if (amount < 10000)
	 cout << "President approves request for " << amount << endl;
      else
	 Administrator::handleRequest(amount);
   }
};

int main(){
   Administrator *tp = new Teller(new Manager(new Finance(new President)));
/*
   Administrator *tp = new Teller(new President);
*/
   int amount = 0;
   cout << "How much money would you like to withdraw? ";
   cin >> amount;
   if (amount > 0) tp->handleRequest(amount);
}
