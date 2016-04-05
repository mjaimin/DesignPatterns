#Single Responsibility Principle
###Principle###
A class should have one, and only one, reason to change.

Principle is related to Designing software module - a class or a function

A module should perform only one task.

This principle is about Creation.
###What is responsibility?###
In the context of the Single Responsibility Principle (SRP) we define a responsibility to be "a reason for change." If you can think of more than one motive for changing a class, then that class has more than one responsibility.

##Problem##
Design Modem class with following functionality.

    Connect(),  Disconnect(),  SendData(),  ReciveData()

These four functions are divided in to two responsibilities of connection and communication.
  
Code
```c
class IConnection{
    public:
	virtual void dial()=0;
	virtual void hangup()=0;
};
class ICommunication{
    public:
	virtual void send()=0;
	virtual void recive()=0;
};
class IModem
{
    public:
	virtual void Connect()=0;
	virtual void Disconnect()=0;
	virtual void SendData()=0;
	virtual void ReciveData()=0;
};

class SimpleModemConnection: public IConnection{
    public:
	void dial(){/*code here*/}
	void hangup(){/*code here*/}
};

class SimpleModemCommunication: public ICommunication{
    public:
	void send(){/*code here*/}
	void recive(){/*code here*/}
};

class Modem : public IModem
{
    private:
	SimpleModemConnection _connectionModule;
	SimpleModemCommunication _communicationModule;

    public:
	Modem(SimpleModemConnection connectionModule, SimpleModemCommunication communicationModule)
	{
	    _connectionModule = connectionModule;
	    _communicationModule = communicationModule;
	}

	void Connect()
	{
	    _connectionModule.dial();
	}

	void Disconnect()
	{
	    _connectionModule.hangup();
	}

	void SendData()
	{
	    _communicationModule.send();
	}

	void ReciveData()
	{
	    _communicationModule.recive();
	}
};
int main()
{
}
```
###Discussions##

This principle states that if we have two reasons to change for a module, we have to split the functionality of module in two modules. Each Module will handle only one responsibility and on future if we need to make one change we are going to make it in the module which handle it. When we need to make a change in a Module having more responsibilities the change might affect the functionality of the other modules.

####Wrong interpretation of the Principle
Most developers interpret to mean that a class should perform only one task. But it's not only classes, functions you implement in code during development should also perform only one task. 