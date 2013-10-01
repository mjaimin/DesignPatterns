#include <iostream>
#include <string>
#include <list>

using namespace std;

class stock;
class investorBase
{
public:
   virtual void update(stock *)  = 0;
   virtual string investorName() = 0;
};

class investor : public investorBase
{
private:
   string m_investorName;
public:
   investor(string name) : m_investorName(name) { }
   virtual string investorName() { return m_investorName; }
   virtual void update(stock *stock);
};

class stock
{
private:
   string               m_stockSymbol;
   double               m_stockPrice;
   list<investorBase *> m_investorList;
protected:
   stock(string symbol, double price) : m_stockSymbol(symbol), m_stockPrice(price), m_investorList(0)
   {
      cout << "Created stock for " << m_stockSymbol << " with price: " << m_stockPrice << "\n";
   }

public:

   void registerObserver(investorBase *investor)
   {
      m_investorList.push_back(investor);
      cout << investor->investorName() << " is now observing " << m_stockSymbol << " stock.\n";
   }

   void removeObserver(investorBase *investor)
   {
      m_investorList.remove(investor);
      cout << investor->investorName() << " not interested in observing " << m_stockSymbol << " stock anymore." << "\n";
   }

   void notifyObserver()
   {
      list<investorBase *>::iterator it = m_investorList.begin();
      while (it != m_investorList.end())
      {
         (*it)->update(this);
         ++it;
      }
   }

   void setStockPrice(double price)
   {
      m_stockPrice = price;
      notifyObserver();
   }

   string getStockSymbol() { return m_stockSymbol; }
   double getStockPrice() { return m_stockPrice; }
};

class companyStock : public stock
{
public:
   companyStock(string symbol, double price) : stock(symbol, price) { }
};

void investor::update(stock *stock)
{
   cout << "Notified " << m_investorName << " about " << stock->getStockSymbol() << " stock price change to " << stock->getStockPrice() << ".\n";
}


int main()
{
   companyStock *c1 = new companyStock("IBM", 123.0);

   investor *i1 = new investor("Sorros");

   c1->registerObserver(i1);

   c1->setStockPrice(125.0);

   investor *i2 = new investor("Berkshire");
   c1->registerObserver(i2);

   c1->setStockPrice(145.0);

   c1->removeObserver(i1);

   c1->setStockPrice(165.0);

   delete i1;
   delete i2;
   delete c1;

   return 0;
}
