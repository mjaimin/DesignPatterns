#include <string>
#include <iostream>
#include <vector>

class IIterator
{
public:

   virtual std::string FirstItem()   = 0;
   virtual void NextItem()           = 0;
   virtual std::string CurrentItem() = 0;
   virtual bool IsDone()             = 0;
};

class IAggregate
{
public:

   virtual IIterator *GetIterator()            = 0;
   virtual std::string& getItem(int itemIndex) = 0;
   virtual void AddValue(std::string value)    = 0;
   virtual int Count() = 0;
};

class ConcreteIterator : public IIterator
{
private:
   IAggregate *m_aggregate;
   int        m_currentIndex;

public:
   ConcreteIterator(IAggregate *aggregate) : m_currentIndex(0), m_aggregate(aggregate) { }
   std::string FirstItem() { return m_aggregate->getItem(0); }
   void NextItem() { m_currentIndex += 1; }
   std::string CurrentItem() { return m_aggregate->getItem(m_currentIndex); }
   bool IsDone() { return (m_currentIndex < m_aggregate->Count()) ? false : true; }
};

class ConcreteAggregate : public IAggregate
{
private:
   std::vector<std::string> m_Vect;

public:
   ConcreteAggregate(void) { }

//Helper function to populate the collection
   void AddValue(std::string value) { m_Vect.push_back(value); }

   IIterator *GetIterator()
   {
      IIterator *iter = new ConcreteIterator(this);

      return iter;
   }

   std::string& getItem(int itemIndex)   { return m_Vect[itemIndex]; }

   int Count()   { return m_Vect.size(); }
};

int main()
{
   IAggregate *aggr     = new ConcreteAggregate;
   IIterator  *iterator = new ConcreteIterator(aggr);

   aggr->AddValue("2");
   aggr->AddValue("1");
   aggr->AddValue("3");
   aggr->AddValue("4");
   aggr->AddValue("5");
   aggr->AddValue("6");
   aggr->AddValue("7");
   aggr->AddValue("8");
   aggr->AddValue("9");
   aggr->AddValue("10");

   IIterator *iter = aggr->GetIterator();

   for (/*iter->FirstItem()*/; iter->IsDone() == false; iter->NextItem())
   {
      std::cout << iter->CurrentItem() << std::endl;
   }

   return 0;
}
