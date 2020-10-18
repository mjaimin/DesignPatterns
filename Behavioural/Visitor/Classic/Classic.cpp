#include <iostream>

class IElement;

class IVisitor
{
    public:
        virtual ~IVisitor() {}
        virtual void Visit(IElement *) = 0;
};

class IElement
{
    public:
        virtual ~IElement() {}
        virtual void Accept(IVisitor&) = 0;
        virtual std::string getName()  = 0;
};

class VisitorA : public IVisitor
{
    public:
        void Visit(IElement *elm) {
            std::cout << "VisitorA -> " << elm->getName() << std::endl; }
};

class VisitorB : public IVisitor
{
    public:
        void Visit(IElement *elm) {
            std::cout << "VisitorB -> " << elm->getName() << std::endl; }
};

class ElementA : public IElement
{
    public:
        ElementA() {}

        void Accept(IVisitor& v) {
            v.Visit(this); }

        std::string getName() {
            return("ElementA"); }
};

class ElementB : public IElement
{
    public:
        ElementB() {}

        void Accept(IVisitor& v) {
            v.Visit(this); }

        std::string getName() {
            return("ElementB"); }
};

int main()
{
    ElementA elmA;
    ElementB elmB;
    VisitorA visA;
    VisitorB visB;

    elmA.Accept(visA);
    elmA.Accept(visB);
    elmB.Accept(visB);
    elmB.Accept(visA);

    return 0;
}
