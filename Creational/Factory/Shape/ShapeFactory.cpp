#include <iostream>
#include <string.h>

class Shape {
    public:
        virtual void draw() = 0;
};

class Triangle: public Shape {
    public:
        void draw() {
            std::cout << "Triangle Shape \n";
        }
};

class Circle: public Shape  {
    public:
        void draw() {
            std::cout << "Circle Shape \n";
        }
};

class Square: public Shape {
    public:
        void draw() {
            std::cout << "Square Shape \n";
        }
};

class ShapeFactory {
    public:
        virtual Shape *createShape(std::string type) {
            if(type.compare("Circle") == 0) {
                return new Circle;
            }
            else if(type.compare("Triangle") == 0) {
                return new Triangle;
            }
            else if(type.compare("Square") == 0) {
                return new Square;
            }
        }
};

class Factory: public ShapeFactory {
    Shape *createShape(std::string type) {
        if(type.compare("Circle") == 0) {
            return new Circle;
        }
        else if(type.compare("Triangle") == 0) {
            return new Triangle;
        }
        else if(type.compare("Square") == 0) {
            return new Square;
        }
    }
};

int main()
{
    ShapeFactory* shapeFactory = NULL;
    Shape *shape = NULL;

    shapeFactory = new Factory;

    shape = shapeFactory->createShape(std::string("Triangle"));
    shape -> draw();
    shape = shapeFactory->createShape(std::string("Circle"));
    shape -> draw();
    shape = shapeFactory->createShape(std::string("Square"));
    shape -> draw();

    return 0;
}
