#pragma once
#include <iostream>
class Beverage
{
public:
	Beverage();
	std::string description; 
	virtual std::string getDescription( void );
	virtual double cost( void ) = 0;
};