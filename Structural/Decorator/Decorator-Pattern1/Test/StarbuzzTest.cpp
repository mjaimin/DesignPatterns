#include <iostream>
#include <string>

#include "../Component/Beverage.h"
#include "../Component/Espresso.h"
#include "../Decorator/Milk.h"
#include "../Decorator/Mocha.h"
#include "../Decorator/Soy.h"
#include "../Decorator/Whip.h"
#include "../Component/HouseBlend.h"
#include "../Component/DarkRoast.h"
int main()
{

	Beverage* beverage = new Espresso();
	std::cout << beverage->getDescription() << ": $ "<< beverage->cost() << std::endl;

	Beverage* beverage2 = new DarkRoast();
	beverage2 = new Mocha(beverage2);
	beverage2 = new Mocha(beverage2);
	beverage2 = new Whip(beverage2);
	std::cout << beverage2->getDescription() << ": $ "<< beverage2->cost() << std::endl;

	Beverage* beverage3 = new HouseBlend();
	beverage3 = new Milk(beverage3);
	beverage3 = new Mocha(beverage3);
	beverage3 = new Soy(beverage3);
	std::cout << beverage3->getDescription() << ": $ "<< beverage3->cost() << std::endl;

}