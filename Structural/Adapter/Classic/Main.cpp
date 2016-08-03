#include <iostream>
using namespace std;
//Adaptee is like electric socket on wall
class Adaptee {
    public:
	void SpecificRequest() { cout << "I do work specific way..." << endl; }
};
//Target is like different kind of plug not supported by wall socket
class Target {
    public:
	virtual void newRequest() { cout << "Target's new request..." << endl; }
};
//Plug adapter
class Adapter : public Target, private Adaptee {
    private:
	Adaptee *adaptee;
    public:
	Adapter(Adaptee *obj) : adaptee(obj) {}
	void newRequest() 
	{
	    adaptee->SpecificRequest(); 
	}
};

int main()
{
    Adaptee *adaptee = new Adaptee();
    Target  *target  = new Adapter(adaptee);

    // Aim is target newRequest should work exactly the same way as Adaptee
    target->newRequest();

    delete target;
    delete adaptee;

    return 0;
}
