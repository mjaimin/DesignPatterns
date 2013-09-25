#include <iostream>
using namespace std;

/* Implementor*/
class DrawingAPI {
    public:
	virtual void drawCircle(double x, double y, double radius) = 0;
	virtual ~DrawingAPI() {}
};

/* Abstraction*/
class Shape {
    public:
	virtual ~Shape() {}
	virtual void draw() = 0;
	virtual void resizeByPercentage(double pct) = 0;
};

/* Concrete ImplementorA*/
class DrawingAPI1 : public DrawingAPI {
    public:
	void drawCircle(double x, double y, double radius) 
	{
	    cout << "API1.circle at " << x << ':' << y << ' ' << radius << endl;
	}
};

/* Concrete ImplementorB*/
class DrawingAPI2 : public DrawingAPI {
    public:
	void drawCircle(double x, double y, double radius) 
	{
	    cout << "API2.circle at " << x << ':' << y << ' ' <<  radius << endl;
	}
};

/* Refined Abstraction*/
class CircleShape : public Shape {
    public:
	CircleShape(double x, double y,double radius, DrawingAPI *drawingAPI) :
	    X(x), Y(y), Radius(radius), m_drawingAPI(drawingAPI){}
	void draw() 
	{
	    m_drawingAPI->drawCircle(X, Y, Radius);
	}
	void resizeByPercentage(double pct) 
	{
	    Radius *= pct;
	}
    private:
	double X, Y, Radius;
	DrawingAPI *m_drawingAPI;
};

int main(void) {
    //DrawingAPI1* drawingAPI = new DrawingAPI1;// directly pass it to Abstraction
    CircleShape circle1(1,2,3,new DrawingAPI1());
    CircleShape circle2(5,7,11,new DrawingAPI2());
    // any time changes can be performed in this level only using Abstraction
    circle1.resizeByPercentage(2.5);
    circle2.resizeByPercentage(2.5);
    // Draw shape any time in application
    circle1.draw();
    circle2.draw();
    return 0;
}
