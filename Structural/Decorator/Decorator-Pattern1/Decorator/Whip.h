#include "CondimentDecorator.h"
class Whip :public CondimentDecorator
{
	Beverage* beverage;

public:
	Whip(Beverage* beverage);
	std::string getDescription();
	double cost();

};
