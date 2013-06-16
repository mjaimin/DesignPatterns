#include <iostream>
#include "sortedList.h"
#include "quickSort.h"
#include "mergeSort.h"

using namespace std;

int main()
{
    sortedList* studentRecords = new sortedList();
    
    studentRecords->addNumberToList(1);
    studentRecords->addNumberToList(5);
    studentRecords->addNumberToList(9);

    sortStrategy* qs = new quickSort();
    studentRecords->setSortStrategy(qs);
    studentRecords->sortFunction();

    sortStrategy* ms = new mergeSort();
    studentRecords->setSortStrategy(ms);
    studentRecords->sortFunction();

    delete qs;
    delete ms;    

    return 0;
}
