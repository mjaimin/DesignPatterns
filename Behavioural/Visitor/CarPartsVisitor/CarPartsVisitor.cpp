#include <iostream>
#include <string>
class Wheel;
class Engine;
class Body;
class Car;
class CarElementVisitor;

class CarElementVisitor {
public:
   virtual void visit(Wheel *wheel)   = 0;
   virtual void visit(Engine *engine) = 0;
   virtual void visit(Body *body)     = 0;
   virtual void visit(Car *car)       = 0;
};

class CarElement {
public:
   virtual void accept(CarElementVisitor *visitor) = 0;
};

class Wheel : public CarElement {
public:
   std::string Name;
   Wheel(std::string name) : Name(name) {}

   void accept(CarElementVisitor *visitor) {
      visitor->visit(this); }
};

class Engine : public CarElement {
public:
   void accept(CarElementVisitor *visitor) {
      visitor->visit(this); }
};

class Body : public CarElement {
public:
   void accept(CarElementVisitor *visitor) {
      visitor->visit(this); }
};

class Car : public CarElement {
   CarElement *FLWheel;
   CarElement *FRWheel;
   CarElement *BLWheel;
   CarElement *BRWheel;
   CarElement *body;
   CarElement *engine;

public:
   Car()
   {
      FLWheel = new Wheel("front left");
      FRWheel = new Wheel("front right");
      BLWheel = new Wheel("back left");
      BRWheel = new Wheel("back right");
      body    = new Body();
      engine  = new Engine();
   }

   void accept(CarElementVisitor *visitor)
   {
      FLWheel->accept(visitor);
      FRWheel->accept(visitor);
      BLWheel->accept(visitor);
      BLWheel->accept(visitor);
      body->accept(visitor);
      engine->accept(visitor);

      visitor->visit(this);
   }
};

class CarElementPrintVisitor : public CarElementVisitor {
public:
   void visit(Wheel *wheel) {
      std::cout << "Visiting " << wheel->Name << " wheel" << std::endl; }

   void visit(Engine *engine) {
      std::cout << "Visiting engine" << std::endl; }

   void visit(Body *body) {
      std::cout << "Visiting body" << std::endl; }

   void visit(Car *car) {
      std::cout << "Visiting car" << std::endl; }
};

class CarElementDoVisitor : public CarElementVisitor {
public:
   void visit(Wheel *wheel) {
      std::cout << "Kicking my " << wheel->Name << " wheel" << std::endl; }

   void visit(Engine *engine) {
      std::cout << "Starting my engine" << std::endl; }

   void visit(Body *body) {
      std::cout << "Moving my body" << std::endl; }

   void visit(Car *car) {
      std::cout << "Starting my car" << std::endl; }
};

int main()
{
   CarElement *car = new Car();

   car->accept(new CarElementPrintVisitor());
   car->accept(new CarElementDoVisitor());
}
