##The Interface Segregation Principle##
###Principle###
Clients should not be forced to depend upon interfaces that they do not use.

###Discussion###
-	This means that when we write our interfaces we should take care to add only methods that should be there.
-	If we add methods that should not be there the classes implementing the interface will have to implement those methods as well.
-	For example if we create an interface called Worker and add a method lunch break, all the workers will have to implement it. What if the worker is a robot?
-	This is bad design, because the interface is doing too much, The solution is to separate the interfaces for work() and eat()


```CPP
#include <list>
class ILogLocation
{
    public:
	virtual void Log()=0;
	virtual void ChangeLogLocation()=0;
};

class DiskLogLocation : public ILogLocation
{
    public:
	DiskLogLocation() {}
	void Log() {
	    // do something to log to  a file here
	}
	void ChangeLogLocation() {
	    // do something to change to a new log-file path here
	}
};

class EventLogLocation : public ILogLocation
{
    public:
	EventLogLocation() {}
	void Log() {
	    // do something to log to the event-viewer here
	}
	void ChangeLogLocation() {
	    //no implementation
	    return;
	}
};
int main()
{
    std::list<ILogLocation*> logLocations;
    logLocations.push_back( new DiskLogLocation());
    logLocations.push_back( new EventLogLocation());

    for (std::list<ILogLocation*>::iterator it = logLocations.begin(); it != logLocations.end(); it++)
    {
	(*it)->ChangeLogLocation();
    }
}

```


Above are two implementations of the ILogLocation interface. Both implement the ChangeLogLocation() method, but only our DiskLogLocation has non dummy implementation.  The ChangeLogLocation() implementation for the EventLogLocation object may introduce bugs and should be avoided.

So here's what we can do instead:


```cpp
class ILogLocation
{
    virtual void Log()=0;
};
class ILogLocationChanger
{
    virtual void ChangeLogLocation()=0;
};
class DiskLogLocation : public ILogLocation, public ILogLocationChanger
{
    public:
	DiskLogLocation() {}
	void Log() {
	    // do something to log to  a file here
	}
	void ChangeLogLocation() {
	    // do something to change to a new log-file path here
	}
};

class EventLogLocation : public ILogLocation
{
    public:
	EventLogLocation() {}
	void Log()
	{
	    // do something to log to the event-viewer here
	}
};

```