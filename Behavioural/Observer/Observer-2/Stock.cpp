#include <iostream>

#include "stock.h"
#include "investorbase.h"

stock::stock(string symbol, double price)
    : m_stockSymbol(symbol)
    , m_stockPrice(price)
    , m_investorList(0)
{
    cout<<"Created stock for "<<m_stockSymbol<<" with price: "<<m_stockPrice<<"\n";
}

void stock::registerObserver(investorBase* investor)
{
    m_investorList.push_back(investor);
    cout<<investor->investorName()<<" is now observing "<<m_stockSymbol<<" stock.\n";
}

void stock::removeObserver(investorBase* investor)
{
    m_investorList.remove(investor);
    cout<<investor->investorName()<<" not interested in observing "<<m_stockSymbol<<" stock anymore."<<"\n";
}

void stock::notifyObserver()
{
    list<investorBase*>::iterator it = m_investorList.begin();
    while(it != m_investorList.end()) {
      (*it)->update(this);
      ++it;
    }
}

void stock::setStockPrice(double price)
{
    m_stockPrice = price;
    notifyObserver();
}
