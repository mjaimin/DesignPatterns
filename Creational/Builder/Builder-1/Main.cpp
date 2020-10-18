#include <iostream>
#include <string>

/* Car parts */
class Wheel {
    private:
        int size;
    public:
        Wheel(int sz) : size(sz) {}
};

class Engine {
    int horsepower;
    public:
    Engine(int hp) : horsepower(hp) {}
};

class Body {
    private:
        std::string shape;
    public:
        Body(std::string s) : shape(s) {}
};

/* Final product -- a car */
class Car {
    public:
        Wheel  *wheels[4];
        Engine *engine;
        Body   *body;
};

/* IBuilder is responsible for constructing the smaller parts */
class IBuilder
{
    public:
        virtual Wheel *buildWheel()   = 0;
        virtual Engine *buildEngine() = 0;
        virtual Body *buildBody()     = 0;
};

/* Concrete builder for Jeep SUV cars */
class JeepBuilder : public IBuilder
{
    public:
        Wheel *buildWheel() { return new Wheel(22); }
        Engine *buildEngine() { return new Engine(400); }
        Body *buildBody() { return new Body("SUV"); }
};

/* Concrete builder for Nissan family cars */
class NissanBuilder : public IBuilder
{
    public:
        Wheel *buildWheel() { return new Wheel(16); }
        Engine *buildEngine() { return new Engine(85); }
        Body *buildBody() { return new Body("Hatchback"); }
};

/* Director is responsible for the whole process */
class Director
{
    IBuilder *builder;

    public:
    void setBuilder(IBuilder *newBuilder)
    {
        builder = newBuilder;
    }

    Car *constructCar()
    {
        Car *car = new Car();

        car->body      = builder->buildBody();
        car->engine    = builder->buildEngine();
        car->wheels[0] = builder->buildWheel();
        car->wheels[1] = builder->buildWheel();
        car->wheels[2] = builder->buildWheel();
        car->wheels[3] = builder->buildWheel();
        return car;
    }
};


int main()
{
    Car *car;      // Final product

    /* A director who controls the process */
    Director director;

    /* Concrete builders */
    NissanBuilder nissanBuilder;

    /* Build a Nissan */
    director.setBuilder(&nissanBuilder);      // using NissanBuilder instance
    car = director.constructCar();

    return 0;
}
