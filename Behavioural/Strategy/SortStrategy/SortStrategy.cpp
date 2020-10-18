#include <iostream>
#include <list>

using namespace std;

class sortStrategy
{
    public:
        virtual void sortNumbers(std::list<int>&) = 0;
};

class SortingContext
{
    private:
        std::list<int> m_ListToSort;
        sortStrategy   *m_sortStrategy;
    public:
        SortingContext() : m_sortStrategy(0) { cout << "There is no intial strategy.\n"; }

        void sortNumbers( ) {
            m_sortStrategy->sortNumbers(m_ListToSort);
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
        void sortNumbers(std::list<int>& listToSort) {
            cout << "Current Strategy is MergeSort.\n";
        }
};

class quickSort : public sortStrategy
{
    public:
        void sortNumbers(std::list<int>& listToSort) {
            cout << "Current Strategy is QuickSort.\n";
        }
};

int main()
{
    SortingContext *studentRecords = new SortingContext();

    studentRecords->addNumberToList(1);
    studentRecords->addNumberToList(5);
    studentRecords->addNumberToList(9);

    sortStrategy *qs = new quickSort();
    studentRecords->setSortStrategy(qs);
    studentRecords->sortNumbers();

    sortStrategy *ms = new mergeSort();
    studentRecords->setSortStrategy(ms);
    studentRecords->sortNumbers();
}
