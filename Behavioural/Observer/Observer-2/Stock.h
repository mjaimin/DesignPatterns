#ifndef __STOCK_H__
#define __STOCK_H__
#include <string>
#include <list>

using namespace std;

class investorBase;
class stock
{
public:
    void registerObserver(investorBase* );
    void removeObserver(investorBase* );
    void notifyObserver();

    string getStockSymbol() {return m_stockSymbol; }
    double getStockPrice() { return m_stockPrice; }
    void setStockPrice(double);
protected:
    stock(string, double );
private:
    string m_stockSymbol;
    double m_stockPrice;
    list<investorBase*> m_investorList;
};
#endif // __STOCK_H__
