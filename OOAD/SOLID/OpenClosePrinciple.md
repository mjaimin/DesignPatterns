## Open Close Principle ##
###Principle###

A Module should be closed for modification and open for extension.

###Motivation###

A clever application design and the code writing part should take care of the frequent changes that are done during the development and the maintaining phase of an application. Usually, many changes are involved when a new functionality is added to an application. Those changes in the existing code should be minimized, since it's assumed that the existing code is already unit tested and changes in already written code might affect the existing functionality in an unwanted manner.

__*Hence you should never need to change existing code or classes: All new functionality can be added by adding new subclasses or methods, or by reusing existing code through delegation.*__

The ***Open Close Principle*** states that the design and writing of the code should be done in a way that new functionality should be added with minimum changes in the existing code. The design should be done in a way to allow the adding of new functionality as new classes, keeping as much as possible existing code unchanged.



####**Procedural Solution to the Square/Circle Problem**
```CPP
class Rectangle{
    public:
	double Width;
	double Height;
};

class Circle{
    public:
	double Radius;
};

class AreaCalculator{
    public:
	double AreaOfCircle( Circle shape)
	{
	    return 3.14*shape.Radius*shape.Radius;
	}
	double AreaOfRectangle( Rectangle shape)
	{
	    return shape.Width*shape.Height;
	}
};
int main()
{}

```
####**OOD solution to Square/Circle problem.**

```CPP
#define PI 3.14
class Shape
{
    public:
	virtual double Area()=0;
};
class Rectangle : public Shape
{
    public:
	double Width;
	double Height;
	double Area()
	{
	    return Width * Height;
	}
};

class Circle : public Shape
{
    public:
	double Radius;
	double Area()
	{
	    return Radius * Radius * PI;
	}
};

class AreaCalculator
{
    public:
	double Area(Shape& shape)
	{
	    return shape.Area();
	}
};

```

