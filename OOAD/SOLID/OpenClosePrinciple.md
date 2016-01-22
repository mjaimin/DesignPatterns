## Open Close Principle ##

###Motivation###

A clever application design and the code writing part should take care of the frequent changes that are done during the development and the maintaining phase of an application. Usually, many changes are involved when a new functionality is added to an application. Those changes in the existing code should be minimized, since it's assumed that the existing code is already unit tested and changes in already written code might affect the existing functionality in an unwanted manner.

__*Hence you should never need to change existing code or classes: All new functionality can be added by adding new subclasses or methods, or by reusing existing code through delegation.*__

The ***Open Close Principle*** states that the design and writing of the code should be done in a way that new functionality should be added with minimum changes in the existing code. The design should be done in a way to allow the adding of new functionality as new classes, keeping as much as possible existing code unchanged.

###Intent###
Software entities like classes, modules and functions should be open for extension but closed for modifications.

####**Procedural Solution to the Square/Circle Problem**
```CPP
enum ShapeType {circle, square};
struct Shape
{
    ShapeType itsType;
};
struct Circle
{
    ShapeType itsType;
    double itsRadius;
    Point itsCenter;
};

struct Square
{
    ShapeType itsType;
    double itsSide;
    Point itsTopLeft;
};

void DrawSquare(struct Square*);
void DrawCircle(struct Circle*);
typedef struct Shape *ShapePointer;

void DrawAllShapes(ShapePointer list[], int n)
{
    int i;
    for (i=0; i<n; i++)
    {
	struct Shape* s = list[i];
	switch (s->itsType)
	{
	    case square:
		DrawSquare((struct Square*)s);
		break;
	    case circle:
		DrawCircle((struct Circle*)s);
		break;
	}
    }
}
```
####**OOD solution to Square/Circle problem.**

```CPP

class Shape
{
    public:
	virtual void Draw() const = 0;
};
class Square : public Shape
{
    public:
	virtual void Draw() const;
};
class Circle : public Shape
{
    public:
	virtual void Draw() const;
};
void DrawAllShapes(Set<Shape*>& list)
{
    for (Iterator<Shape*>i(list); i; i++)
	(*i)->Draw();
}
```

