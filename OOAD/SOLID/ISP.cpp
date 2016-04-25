class IDoor
{
    bool IsDoorOpen;
    public:
    bool getDoorStatus(){ return IsDoorOpen;}
    void setDoorStatus( int status ){ IsDoorOpen = status;}

    virtual void Lock() = 0;
    virtual void Unlock() = 0;
};
class ITimerFunction
{
    public:
	virtual void TimerFunction() = 0; 
};


class SimpleDoor : public IDoor
{
    public:
	void Lock()
	{
	    // method implementation goes here
	}

	void Unlock()
	{
	    // method implementation goes here
	}
};

class AdvancedDoor : public IDoor, public ITimerFunction
{
    public:

	void Lock()
	{
	    // Method implementation goes here...
	}

	void Unlock()
	{
	    // Method implementation goes here...
	}

	void TimerFunction()
	{
	}
};

int main(){}
