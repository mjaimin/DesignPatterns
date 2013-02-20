#pragma once
#include "CondimentDecorator.h"
#include <iostream>

class Milk :public CondimentDecorator
{
	Beverage* beverage;

public:
	Milk(Beverage*);
	std::string getDescription();
	double cost();

};
