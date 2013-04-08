#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__
#include "sortStrategy.h"
#include <list>

class quickSort : public sortStrategy
{
public:
    virtual void sortFunction( std::list<int> & );
};

#endif // __QUICKSORT_H__
