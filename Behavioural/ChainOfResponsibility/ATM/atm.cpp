#include <iostream>
using std::cout; using std::endl; using std::cin;
class CashDispenser{
private:
   CashDispenser *nextDen_;
public:
   CashDispenser(CashDispenser *nextDen=nullptr): nextDen_(nextDen){}
   void dispense(int amount){
      const int bills = amount / getDen();
      const int remainder = amount % getDen();
      if (bills > 0 )
	 cout << bills << " " << getDen() << "-dollar bill(s) " << endl;

      if (remainder !=0){ 
	  if(nextDen_ != nullptr) 
	     nextDen_->dispense(remainder);
	  else
	     cout << "no more handlers to dispense " << remainder << " dollars" << endl;
      }
   }
   int getLowestDen(){
      if(nextDen_ == nullptr) return getDen();
      else
	 return nextDen_->getLowestDen();
   }
   virtual int getDen()=0;
};

class Hundreds: public CashDispenser{
public:
   Hundreds(CashDispenser *nextDen): CashDispenser(nextDen){}
   int getDen() override {return 100;};
};

class Twenties: public CashDispenser{
public:
   Twenties(CashDispenser *nextDen): CashDispenser(nextDen){}
   int getDen() override {return 20;};
};

class Tens: public CashDispenser{
public:
   Tens(CashDispenser *nextDen): CashDispenser(nextDen){}
   int getDen() override {return 10;};
};

int main(){
   Hundreds *bigAtm = new Hundreds(new Twenties(nullptr));
   Hundreds *smallAtm = new Hundreds(new Twenties(new Tens(nullptr)));
   
   cout << "how much money would you like to get? ";
   int amount;
   cin >> amount;

   if(amount % bigAtm->getLowestDen() == 0){
      cout << "Big ATM dispensing" << endl;
      bigAtm -> dispense(amount);
   } else if (amount % smallAtm->getLowestDen() == 0){
      cout << "Small ATM dispensing" << endl;
      smallAtm -> dispense(amount);
   } else
      cout << "amount needs to be divisible by " << smallAtm -> getLowestDen() << endl;
}
