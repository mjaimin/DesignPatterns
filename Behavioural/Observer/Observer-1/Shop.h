#pragma once
#include <iostream>
#include <string>
#include "IObserver.h"

class Shop : IObserver
{
	//Name of the Shop
	std::string name;
    float price;
public:
	Shop(std::string n); 
    void Update(float price);          
};
