#include "CondimentDecorator.h"
class Mocha : public CondimentDecorator
{
	Beverage* beverage;

public:
	Mocha(Beverage* beverage);
	std::string getDescription();
	double cost();

};