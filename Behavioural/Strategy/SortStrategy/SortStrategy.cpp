#include <iostream>
#include <list>

using namespace std;

class sortStrategy
{
public:
   virtual void sortFunction(std::list<int>&) = 0;
};

class sortedList
{
private:
   std::list<int> m_ListToSort;
   sortStrategy   *m_sortStrategy;
public:
   sortedList() : m_sortStrategy(0) { cout << "There is no intial strategy.\n"; }
   void sortFunction( ) {
      m_sortStrategy->sortFunction(m_ListToSort);
   }
   void setSortStrategy(sortStrategy *strategy) {
      std::cout << "Setting a new strategy...\n";
      m_sortStrategy = strategy;
   }

   void addNumberToList(int value) {
      m_ListToSort.push_back(value);
   }
};

class mergeSort : public sortStrategy
{
public:
   void sortFunction(std::list<int>& listToSort) {
      cout << "Current Strategy is MergeSort.\n";
   }
};

class quickSort : public sortStrategy
{
public:
   void sortFunction(std::list<int>& listToSort) {
      cout << "Current Strategy is QuickSort.\n";
   }
};

int main()
{
   sortedList *studentRecords = new sortedList();

   studentRecords->addNumberToList(1);
   studentRecords->addNumberToList(5);
   studentRecords->addNumberToList(9);

   sortStrategy *qs = new quickSort();
   studentRecords->setSortStrategy(qs);
   studentRecords->sortFunction();

   sortStrategy *ms = new mergeSort();
   studentRecords->setSortStrategy(ms);
   studentRecords->sortFunction();
}
