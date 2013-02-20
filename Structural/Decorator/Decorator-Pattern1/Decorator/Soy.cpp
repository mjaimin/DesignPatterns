#include "Soy.h"
Soy::Soy(Beverage* beverage)
{
	this->beverage = beverage;
}

std::string Soy::getDescription()
{
	return beverage->getDescription().append(", Soy");
}

double Soy::cost()
{
	return 0.2f + beverage->cost();
}