#ifndef __INVESTOR_H__
#define __INVESTOR_H__
#include "investorbase.h"

using namespace std;

class stock;
class investor : public investorBase
{
public:
    investor(string );
    virtual void update(stock* );

    virtual string investorName() { return m_investorName; }
private:
    string m_investorName;
};
#endif // __INVESTOR_H__
