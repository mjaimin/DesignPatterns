#include <iostream>
#include "investor.h"
#include "stock.h"

investor::investor(string name)
    : m_investorName(name)
{
}

void investor::update(stock* stock)
{
    cout<<"Notified "<<m_investorName<<" about "<<stock->getStockSymbol() <<" stock price change to "<<stock->getStockPrice()<<".\n";
}
