#include "Mocha.h"
Mocha::Mocha(Beverage* beverage)
{
	this->beverage = beverage;
}

std::string Mocha::getDescription()
{
	return beverage->getDescription().append(", Mocha");
}

double Mocha::cost()
{
	return 0.20f + beverage->cost();
}