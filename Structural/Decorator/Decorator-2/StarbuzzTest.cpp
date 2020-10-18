#include <iostream>
#include <string>

class Beverage
{
    public:

        std::string description;

        virtual double cost( void ) = 0;

        Beverage()
        {
            description = "Unkwown beverage";
        }
        virtual std::string getDescription( void )
        {
            return description;
        }
};
//----------------- Beverage Types -------------
class DarkRoast : public Beverage
{
    public:

        DarkRoast()
        {
            description = "Unkwown beverage";
        }
        double cost( void )
        {
            return 0.99f;
        }
};

class Decaf : public Beverage
{
    public:

        Decaf()
        {
            description = "decaf coffee";
        }
        double cost()
        {
            return 2.5f;
        }
};

class Espresso :public Beverage
{
    public:

        Espresso()
        {
            description = "Espresso";
        }
        double cost(void)
        {
            return 1.99f;
        }
};

class HouseBlend : public Beverage
{
    public:

        HouseBlend()
        {
            description = "House blend coffee";
        }
        double cost()
        {
            return 0.89f;
        }
};

//----------------- Beverage Condiment Type -------------

class CondimentDecorator : public Beverage
{
    //cost not implemented so it is abstract
};

class Milk :public CondimentDecorator
{
    Beverage* beverage;
    public:

    Milk(Beverage* beverage)
    {
        this->beverage = beverage;
    }
    std::string getDescription()
    {
        return beverage->getDescription().append(", Milk");
    }
    double cost()
    {
        return 0.20f + beverage->cost();
    }
};

class Mocha : public CondimentDecorator
{
    Beverage* beverage;
    public:

    Mocha(Beverage* beverage)
    {
        this->beverage = beverage;
    }
    std::string getDescription()
    {
        return beverage->getDescription().append(", Mocha");
    }
    double cost()
    {
        return 0.20f + beverage->cost();
    }
};

class Soy : public CondimentDecorator
{
    Beverage* beverage;
    public:

    Soy(Beverage* beverage)
    {
        this->beverage = beverage;
    }
    std::string getDescription()
    {
        return beverage->getDescription().append(", Soy");
    }
    double cost()
    {
        return 0.2f + beverage->cost();
    }
};

class Whip :public CondimentDecorator
{
    Beverage* beverage;
    public:

    Whip(Beverage* beverage)
    {
        this->beverage = beverage;
    }
    std::string getDescription()
    {
        return beverage->getDescription().append(", Soy");
    }
    double cost()
    {
        return 0.2f + beverage->cost();
    }
};

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
