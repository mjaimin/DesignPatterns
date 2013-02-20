#include "Beverage.h"

Beverage::Beverage()
{
	description = "Unkwown beverage";
}

std::string Beverage::getDescription( void )
{
	return description;
}
