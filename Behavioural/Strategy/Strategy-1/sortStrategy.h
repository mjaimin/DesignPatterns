#ifndef __SORTSTRATEGY_H__
#define __SORTSTRATEGY_H__
#include <list>
class sortStrategy
{
public:
    virtual void sortFunction(std::list<int> &) = 0;
};

#endif // __SORTSTRATEGY_H__
