
#include <iostream>
#include "sortedList.h"
#include "sortStrategy.h"
#include "quickSort.h"

using namespace std;

sortedList::sortedList()
    : m_sortStrategy(0)
{
    cout<<"There is no intial strategy.\n";
}

void sortedList::sortFunction(  )
{
    m_sortStrategy->sortFunction( m_ListToSort );
}

void sortedList::setSortStrategy(sortStrategy* strategy)
{ 
    std::cout<< "Setting a new strategy...\n" ;
    m_sortStrategy = strategy;
}

void sortedList::addNumberToList(int value)
{
    // Logic for adding number goes here.
	m_ListToSort.push_back(value);
}
