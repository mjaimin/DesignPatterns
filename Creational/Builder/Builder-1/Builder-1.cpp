#include <iostream>
#include <string>

/* Car parts */
class Wheel { public: int size; };

class Engine { public: int horsepower; };

class Body { public: std::string shape; };

/* Final product -- a car */
class Car
{
public:
	Wheel*   wheels[4];
	Engine*  engine;
	Body* body;

	void getCarSpecs()
	{
		std::cout << "body:" << body->shape << std::endl;
		std::cout << "engine horsepower:" << engine->horsepower << std::endl;
		std::cout << "tire size:" << wheels[0]->size << "'" << std::endl;
	}
};

/* Builder is responsible for constructing the smaller parts */
class Builder
{
public:
	virtual Wheel* buildWheel() = 0;
	virtual Engine* buildEngine() = 0;
	virtual Body* buildBody() = 0;
};

/* Concrete Builder for Jeep SUV cars */
class JeepBuilder : public Builder
{
public:
	Wheel* buildWheel()
	{
		Wheel* wheel = new Wheel();
		wheel->size = 22;// set wheel features
		return wheel;
	}

	Engine* buildEngine()
	{
		Engine* engine = new Engine();
		engine->horsepower = 400;// set engine features
		return engine;
	}

	Body* buildBody()
	{
		Body* body = new Body();
		body->shape = "SUV"; // set body feature
	}
};

/* Concrete builder for Nissan family cars */
class NissanBuilder : public Builder
{
public:
	Wheel* buildWheel()
	{
		Wheel* wheel = new Wheel();
		wheel->size = 16;// set wheel features
		return wheel;
	}

	Engine* buildEngine()
	{
		Engine* engine = new Engine();
		engine->horsepower = 85;// set engine features
		return engine;
	}

	Body* buildBody()
	{
		Body* body = new Body();
		body->shape = "hatchback";// set body feature
	}
};

/* Director is responsible for the whole process */
class Director
{
	Builder* builder;

public:
	void setBuilder(Builder* newBuilder)
	{
		builder = newBuilder;
	}

	Car* constructCar()
	{
		Car* car = new Car();

		car->body = builder->buildBody();

		car->engine = builder->buildEngine();

		car->wheels[0] = builder->buildWheel();
		car->wheels[1] = builder->buildWheel();
		car->wheels[2] = builder->buildWheel();
		car->wheels[3] = builder->buildWheel();

		return car;
	}
};


int main()
{
	Car* car; // Final product

	/* A director who controls the process */
	Director director;

	/* Concrete builders */
	JeepBuilder jeepBuilder;
	NissanBuilder nissanBuilder;

	/* Build a Jeep */
	std::cout << "Jeep" << std::endl;
	director.setBuilder(&jeepBuilder); // using JeepBuilder instance
	car = director.constructCar();
	car->getCarSpecs();

	std::cout << std::endl;

	/* Build a Nissan */
	std::cout << "Nissan" << std::endl;
	director.setBuilder(&nissanBuilder); // using NissanBuilder instance
	car = director.constructCar();
	car->getCarSpecs();

	return 0;
}