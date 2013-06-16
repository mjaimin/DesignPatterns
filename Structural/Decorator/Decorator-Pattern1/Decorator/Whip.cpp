#include "Whip.h"
Whip::Whip(Beverage* beverage)
{
	this->beverage = beverage;
}

std::string Whip::getDescription()
{
	return beverage->getDescription().append(", Soy");
}

double Whip::cost()
{
	return 0.2f + beverage->cost();
}