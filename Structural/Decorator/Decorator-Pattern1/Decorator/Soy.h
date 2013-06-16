#include <iostream>
#include "CondimentDecorator.h"
class Soy : public CondimentDecorator
{
	Beverage* beverage;

public:
	Soy(Beverage* beverage);
	std::string getDescription();
	double cost();

};
