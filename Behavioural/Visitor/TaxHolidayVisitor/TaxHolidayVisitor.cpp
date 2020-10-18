// The visitor pattern is used when you have to perform
#include <iostream>
using namespace std;

// the same action on many objects of different types
class Liquor;
class Tobacco;
class Necessity;

class Visitor {

    // Created to automatically use the right
    // code based on the Object sent
    // Method Overloading

    public:
        double visit(Liquor* liquorItem);
        double visit(Tobacco* tobaccoItem);
        double visit(Necessity* necessityItem);

};

class Visitable {

    // Allows the Visitor to pass the object so
    // the right operations occur on the right
    // type of object.

    // accept() is passed the same visitor object
    // but then the method visit() is called using
    // the visitor object. The right version of visit()
    // is called because of method overloading

    public:
        double accept(Visitor* visitor);

};



class Liquor: public Visitable {
    private:
        double price;

    public:
        Liquor(double item) : price(item) { }
        double accept(Visitor* visitor) {
            return visitor->visit(this);
        }
        double getPrice() { return price; }
};

class Necessity: public Visitable {
    private:
        double price;
    public:
        Necessity(double item) : price(item) { }
        double accept(Visitor* visitor) {
            return visitor->visit(this);
        }
        double getPrice() { return price; }
};

class Tobacco: public Visitable {
    private:
        double price;
    public:
        Tobacco(double item) : price(item) { }
        double accept(Visitor* visitor) {
            return visitor->visit(this);
        }
        double getPrice() { return price; }
};

// Concrete Visitor Class

class TaxVisitor: public Visitor {

    // This is created so that each item is sent to the
    // right version of visit() which is required by the
    // Visitor interface and defined below

    public:
        TaxVisitor() { }
        double visit(Liquor* liquorItem) {
            std::cout << "Liquor Item: Price with Tax"<< std::endl;
            return ((liquorItem->getPrice() * .18) + liquorItem->getPrice());
        }
        double visit(Tobacco* tobaccoItem) {
            std::cout << "Tobacco Item: Price with Tax"<< std::endl;
            return (tobaccoItem->getPrice() * .32) + tobaccoItem->getPrice();
        }
        double visit(Necessity* necessityItem) {
            std::cout << "Necessity Item: Price with Tax"<< std::endl;
            return (necessityItem->getPrice());
        }

};


// Concrete Visitor Class

class TaxHolidayVisitor: public Visitor {

    // This is created so that each item is sent to the
    // right version of visit() which is required by the
    // Visitor interface and defined below

    public:
        TaxHolidayVisitor() {
        }
        double visit(Liquor* liquorItem) {
            std::cout << "Liquor Item: Price with Tax" << std::endl;
            return ((liquorItem->getPrice() * .10) + liquorItem->getPrice());
        }
        double visit(Tobacco* tobaccoItem) {
            std::cout << "Tobacco Item: Price with Tax" << std::endl;
            return ((tobaccoItem->getPrice() * .30) + tobaccoItem->getPrice());
        }
        double visit(Necessity* necessityItem) {
            std::cout << "Necessity Item: Price with Tax" << std::endl;
            return necessityItem->getPrice();
        }

};

int main()
{
    TaxVisitor* taxCalc = new TaxVisitor();
    TaxHolidayVisitor* taxHolidayCalc = new TaxHolidayVisitor();

    Necessity* milk = new Necessity(3.47);
    Liquor* vodka = new Liquor(11.99);
    Tobacco* cigars = new Tobacco(19.99);

    std::cout << milk->accept(taxCalc) << std::endl;
    std::cout << vodka->accept(taxCalc) << std::endl;
    std::cout << cigars->accept(taxCalc) << std::endl;

    std::cout << "TAX HOLIDAY PRICES" << std::endl;

    std::cout << milk->accept(taxHolidayCalc) << std::endl;
    std::cout << vodka->accept(taxHolidayCalc) << std::endl;
    std::cout << cigars->accept(taxHolidayCalc) << std::endl;

}

