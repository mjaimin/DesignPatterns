#include "Milk.h"
Milk::Milk(Beverage* beverage)
{
	this->beverage = beverage;
}

std::string Milk::getDescription()
{
	return beverage->getDescription().append(", Milk");
}

double Milk::cost()
{
	return 0.20f + beverage->cost();
}