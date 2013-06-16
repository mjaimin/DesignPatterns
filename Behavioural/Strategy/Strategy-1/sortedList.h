#ifndef __SORTEDLIST_H__
#define __SORTEDLIST_H__

#include <list>
#include <iostream>
using namespace std;
class sortStrategy;
class sortedList
{
private:
	std::list<int> m_ListToSort;
	sortStrategy* m_sortStrategy;
public:
    sortedList();

    void sortFunction( );
    void setSortStrategy(sortStrategy* );
    void addNumberToList(int );


};

#endif // __SORTEDLIST_H__
