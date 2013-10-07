#include <iostream>
#include <string>
#include <vector>

//object that stores the historical state
class Memento
{
private: std::string state;

public:
   std::string GetState() { return state; }

   void SetState(std::string state) { this->state = state; }
};

//the object that we want to save and restore, such as a check point in an application
class Originator
{
private: std::string state;
public:
   Memento *createMemento()
   {
      Memento *m = new Memento;

      m->SetState(state);
      return m;
   }

   void SetMemento(Memento *m) { state = m->GetState(); }
   //change the state of the Originator
   void SetState(std::string state) { this->state = state; }
   void ShowState() { std::cout << state << std::endl; }
};

//object for the client to access
class Caretaker
{
   //list of states saved
private:
   std::vector<Memento *> mementoList;

   //save state of the originator
public:
   void SaveState(Originator *orig)
   {
      mementoList.push_back(orig->createMemento());
   }

   //restore state of the originator
   void RestoreState(Originator *orig, int stateNumber)
   {
      orig->SetMemento(mementoList.at(stateNumber));
   }
};

int main()
{
   //Originator has to be pointer type or passed as  reference here, because caretacker works on orintor
   // originator handles responsibility of transfering state between Caretaker and Program at any time Originator handles value of momento of requested state
   Originator *orig = new Originator ;
   Caretaker  *caretaker = new Caretaker ;

   // Here "state0" is std::string but this is the object whose state hase to be preserved/retrieve by caretaker using Originator
   // so imagin "state0" as templet<T> object trough out the program
   orig->SetState("state0");
   caretaker->SaveState(orig);      //save state of the originator
   orig->ShowState();

   orig->SetState("state1");
   caretaker->SaveState(orig);      //save state of the originator
   orig->ShowState();

   orig->SetState("state2");
   caretaker->SaveState(orig);      //save state of the originator
   orig->ShowState();

   orig->SetState("state3");
   caretaker->SaveState(orig);      //save state of the originator
   orig->ShowState();

   orig->SetState("state4");
   caretaker->SaveState(orig);      //save state of the originator
   orig->ShowState();

   //restore state of the originator
   caretaker->RestoreState(orig, 2);
   orig->ShowState();      //shows state0
}
