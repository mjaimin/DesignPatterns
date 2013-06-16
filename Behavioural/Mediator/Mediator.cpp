#include <iostream>
#include <string>
#include <list>
class IMediator;
class IColleague
{
public:
	virtual void SendMessage(IMediator* mediator,std::string message)=0;
	virtual void ReceiveMessage(std::string message)=0;
	virtual ~IColleague(){}
};

class IMediator
{
public:
	std::list<IColleague*> ColleagueList;
	virtual void DistributedMessage( IColleague* Sender, std::string message)=0;
	virtual void Register( IColleague* Colleague)=0;
	virtual ~IMediator(){}
};

class ConcreteColleague:public IColleague
{
private:
	std::string name;
public:
	ConcreteColleague(std::string name)
    {
        this->name = name;
    }
	void SendMessage(IMediator* mediator, std::string message)
    {
        mediator->DistributedMessage(this, message);
	}
	void ReceiveMessage( std::string message)
	{
		std::cout << name + " received " + message << std::endl;
	}	
	~ConcreteColleague(){}
};

class ConcreateMediator: public IMediator 
{
public:

	void Register( IColleague* Colleague )
	{
		ColleagueList.push_back( Colleague );
	}
	void DistributedMessage( IColleague* Sender, std::string message )
	{
		for (std::list<IColleague*>::iterator itr = ColleagueList.begin(); itr != ColleagueList.end(); itr++)
		{
			if( *itr == Sender )
			{
				continue;
			}
			(*itr)->ReceiveMessage(message);
		}
	}
	~ConcreateMediator(){}
};


int main()
{
	IColleague* colleagueA =  new ConcreteColleague("ColleagueA");
	IColleague* colleagueB =  new ConcreteColleague("ColleagueB");
	IColleague* colleagueC =  new ConcreteColleague("ColleagueC");
	IColleague* colleagueD =  new ConcreteColleague("ColleagueD");

	ConcreateMediator ConcreateMediator1;
	ConcreateMediator ConcreateMediator2;
	IMediator* mediator1 =  &ConcreateMediator1;
	IMediator* mediator2 =  &ConcreateMediator2;

	mediator1->Register(colleagueA);
	mediator1->Register(colleagueB);
	mediator1->Register(colleagueC);

	colleagueA->SendMessage( mediator1, "MessageX Sent from ColleagueA");

	mediator2->Register(colleagueB);
	mediator2->Register(colleagueD);

	colleagueB->SendMessage( mediator2, "MessageY Sent from ColleagueB");


}