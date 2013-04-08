#ifndef __INVESTORBASE_H__
#define __INVESTORBASE_H__
#include <string>

using namespace std;

class stock;
class investorBase
{
public:
    virtual void update(stock* ) = 0;
    virtual string investorName() = 0;
};
#endif // __INVESTORBASE_H__
