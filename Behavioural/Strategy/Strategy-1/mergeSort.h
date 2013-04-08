#ifndef __MERGESORT_H__
#define __MERGESORT_H__
#include "sortStrategy.h"
#include <list>
class mergeSort : public sortStrategy
{
public:
    virtual void sortFunction(std::list<int> &);
};

#endif // __MERGESORT_H__
