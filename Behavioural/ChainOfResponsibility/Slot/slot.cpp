#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Slot {
    private:
	int  value_;
	int  count_;
    public:
	Slot( int val ) 
	{
	    value_ = val;
	    count_ = 0;
	}
	int accept( int coin ) 
	{
	    if (coin == value_) 
	    {
		count_++;
		return 1;
	    }
	    return 0; 
	}
	int getCount() { return count_; }
};

class Quarter : public Slot {
public:
   Quarter() : Slot( 25 ) { }
};

class Dime : public Slot {
public:
   Dime() : Slot( 10 ) { }
};

class Nickel : public Slot {
public:
   Nickel() : Slot( 5 ) { }
};

class Penny : public Slot {
public:
   Penny() : Slot( 1 ) { }
};

int pickCoin()
{
   static int choices[4] = { 1, 5, 10, 25 };
   return choices[rand() % 4];
}

int main( void )
{
   Slot*    slots[4];
   slots[0] = new Quarter;
   slots[1] = new Dime;
   slots[2] = new Nickel;
   slots[3] = new Penny;
   int      i, coin, total;
   time_t   t;
   srand((unsigned) time(&t));

   for (i=0, total=0; i < 10; i++)
   {
      coin = pickCoin();
      cout << coin << " ";
      total += coin;
      for (int j=0; j < 4; j++)
         if (slots[j]->accept( coin )) break;
   }
   cout << "\ntotal deposited is $" << total/100 << "."
      << (total%100 < 10 ? "0" : "") << total%100 << endl;
   cout << "quarters - " << slots[0]->getCount() << endl;
   cout << "dimes    - " << slots[1]->getCount() << endl;
   cout << "nickels  - " << slots[2]->getCount() << endl;
   cout << "pennies  - " << slots[3]->getCount() << endl;
}

