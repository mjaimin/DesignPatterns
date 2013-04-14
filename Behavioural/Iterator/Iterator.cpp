#include <string>
#include <iostream>
#include <vector>

class IIterator
{
public:

	virtual std::string FirstItem() = 0;
	virtual std::string NextItem() = 0;
	virtual std::string CurrentItem() = 0;
	virtual bool IsDone() = 0;		
};

class IAggregate
{
public:

	virtual IIterator* GetIterator() = 0;
	virtual std::string& operator[](int itemIndex) = 0;
	virtual int Count() = 0;
};

class MyIterator : public IIterator
{
	IAggregate *m_aggregate;
	int m_currentIndex;

public:
	MyIterator(IAggregate *aggregate);	
	std::string FirstItem();
	std::string NextItem();
	std::string CurrentItem();
	bool IsDone();
};

class MyAggregate : public IAggregate
{
	std::vector<std::string> m_Vect;

public:
	MyAggregate(void);
	//Helper function to populate the collection
	void AddValue(std::string value);
	IIterator* GetIterator();
	std::string& operator[](int itemIndex);
	int Count();
};

MyIterator::MyIterator(IAggregate *aggregate)
	: m_currentIndex(0)
	, m_aggregate(aggregate)
{

}

std::string MyIterator::FirstItem()
{
	m_currentIndex = 0;
	return (*m_aggregate)[m_currentIndex];
}

std::string MyIterator::NextItem()
{
	m_currentIndex += 1;

	if (IsDone() == false)
	{
		return (*m_aggregate)[m_currentIndex];
	}
	else
	{
		return "";
	}
}

std::string MyIterator::CurrentItem()
{
	return (*m_aggregate)[m_currentIndex];
}

bool MyIterator::IsDone()
{
	if (m_currentIndex < m_aggregate->Count())
	{
		return false;
	}
	return true;
}

MyAggregate::MyAggregate(void)	
{}

//Helper function to populate the collection
void MyAggregate::AddValue(std::string value)
{
	m_Vect.push_back(value);
}

IIterator* MyAggregate::GetIterator()
{
	IIterator *iter = new MyIterator(this); 
	return iter;
}

std::string& MyAggregate::operator[](int itemIndex)
{
	return m_Vect[itemIndex];
}	

int MyAggregate::Count()
{
	return m_Vect.size();
}

int main()
{
	MyAggregate aggr;;

	aggr.AddValue("1");
	aggr.AddValue("2");
	aggr.AddValue("3");
	aggr.AddValue("4");
	aggr.AddValue("5");
	aggr.AddValue("6");
	aggr.AddValue("7");
	aggr.AddValue("8");
	aggr.AddValue("9");
	aggr.AddValue("10");

	IIterator *iter = aggr.GetIterator();

	for (std::string s = iter->FirstItem(); iter->IsDone() == false;  s = iter->NextItem() )
	{
		std::cout << s << std::endl;;
	}

	return 0;
}