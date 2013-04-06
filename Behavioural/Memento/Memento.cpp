#include <iostream>
#include <string>
#include <vector>

//object that stores the historical state
class Memento
{
private: std::string state;

public:
	std::string GetState()
	{
		return state;
	}

	void SetState(std::string state)
	{
		this->state = state;
	}
};

//the object that we want to save and restore, such as a check point in an application
class Originator
{
private: std::string state;


		 //for restoring the state
public:
	//for saving the state
	Memento* newMemento()
	{
		Memento* m = new Memento;
		m->SetState(state);
		return m;
	}


	void SetMemento(Memento* m)
	{
		state = m->GetState();
	}

	//change the state of the Originator
	void SetState(std::string state)
	{
		this->state = state;
	}

	//show the state of the Originator
	void ShowState()
	{
		std::cout << state << std::endl;
	}
};

//object for the client to access
class Caretaker
{
	//list of states saved
private:
	std::vector<Memento*> mementoList;

	//save state of the originator
public:
	void SaveState(Originator* orig)
	{
		mementoList.push_back( orig->newMemento() );
	}

	//restore state of the originator
	void RestoreState(Originator* orig, int stateNumber)
	{
		orig->SetMemento(mementoList.at(stateNumber));
	}
};

int main()
{
	//Originator has to be pointer type or passed as  reference here, because caretacker works on orintor
	Originator orig ;
	Caretaker caretaker;

	orig.SetState("state0");
	caretaker.SaveState(&orig); //save state of the originator
	orig.ShowState();

	orig.SetState("state1");
	caretaker.SaveState(&orig); //save state of the originator
	orig.ShowState();

	orig.SetState("state2");
	caretaker.SaveState(&orig); //save state of the originator
	orig.ShowState();

	orig.SetState("state3");
	caretaker.SaveState(&orig); //save state of the originator
	orig.ShowState();

	orig.SetState("state4");
	caretaker.SaveState(&orig); //save state of the originator
	orig.ShowState();

	//restore state of the originator
	caretaker.RestoreState(&orig, 2);
	orig.ShowState(); //shows state0
}


