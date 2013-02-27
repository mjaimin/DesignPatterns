#include <iostream>
#include <map>
#include <string>
using namespace std;

class IAlien
{
public:
	string shape; //intrinsic state

	virtual string GetColor(int madLevel)=0; //extrinsic state
	std::string getShape(){ return shape; }
};

class LargeAlien : public IAlien
{
public:
	LargeAlien();
	string GetColor(int madLevel) //extrinsic state
	{
		string colorValue;
		if (madLevel == 0)
			colorValue = "Green";
		else if (madLevel == 1)
			colorValue = "Red";
		else
			colorValue = "Blue";
		return colorValue;
	}
};
LargeAlien::LargeAlien()
{
	shape = "Large Shape";
}

class LittleAlien : public IAlien
{
public:
	LittleAlien();
	string GetColor(int madLevel) //extrinsic state
	{
		string colorValue;
		if (madLevel == 0)
			colorValue = "Red";
		else if (madLevel == 1)
			colorValue = "Blue";
		else
			colorValue = "Green";
		return colorValue;
	}
};
LittleAlien::LittleAlien()
{
	shape = "Little Shape";
}
class AlienFactory
{
	std::map<int, IAlien* > list;
public: 
	void SaveAlien(int index, IAlien* alien)	{	list[index] = alien;	}

	IAlien* GetAlien(int index)	{	return list[index];	}
};

int main()
{
	//create Aliens and store in factory
	AlienFactory* factory = new AlienFactory();
	factory->SaveAlien(0, new LargeAlien());
	factory->SaveAlien(1, new LittleAlien());

	//now access the flyweight objects
	IAlien* a = factory->GetAlien(0);
	IAlien* b = factory->GetAlien(1);

	//show intrinsic states, all accessed in memory without calculations
	std::cout << "Showing intrinsic states..."<< std::endl;
	std::cout << "Alien of type 0 is " << a->getShape() << std::endl;
	std::cout << "Alien of type 1 is " << b->getShape() << std::endl;

	//show extrinsic states, need calculations
	std::cout << "Showing extrinsic states..."<< std::endl;
	std::cout << "Alien of type 0 color is " << a->GetColor(0)<< std::endl;
	std::cout << "Alien of type 0 color is " << a->GetColor(1)<< std::endl;
	std::cout << "Alien of type 1 color is " << b->GetColor(0)<< std::endl;
	std::cout << "Alien of type 1 color is " << b->GetColor(1)<< std::endl;
}
