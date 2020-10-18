#include <list>
#include <iostream>
#include <string>

class IEmployee
{
    public:
        virtual void ShowHappiness() = 0;
};

class Worker: public IEmployee
{
    private:
        std::string name;
        int happiness;

    public:
        Worker(std::string name, int happiness)
        {
            this->name = name;
            this->happiness = happiness;
        }

        void ShowHappiness()
        {
            std::cout << name <<  " showed happiness level of " << happiness << std::endl;
        }
};

class Supervisor: public IEmployee
{
    private:
        std::string name;
        int happiness;
        std::list<IEmployee*> subordinate;

    public:
        Supervisor(std::string name, int happiness)
        {
            this->name = name;
            this->happiness = happiness;
        }

        void ShowHappiness()
        {
            std::cout << name << " showed happiness level of " << happiness << std::endl;
            //show all the subordinate's happiness level
            for (std::list<IEmployee*>::iterator it = subordinate.begin(); it != subordinate.end(); it++)
                (*it)->ShowHappiness();
        }

        void AddSubordinate(IEmployee* employee)
        {
            subordinate.push_back(employee);
        }
};


int main()
{
    Worker* a = new Worker("Worker Tom", 5);
    Supervisor* b = new Supervisor("Supervisor Mary", 6);
    Supervisor* c = new Supervisor("Supervisor Jerry", 7);
    Supervisor* d = new Supervisor("Supervisor Bob", 9);
    Worker* e = new Worker("Worker Jimmy", 8);

    //set up the relationships
    b->AddSubordinate(a); //Tom works for Mary
    c->AddSubordinate(b); //Mary works for Jerry
    c->AddSubordinate(d); //Bob works for Jerry
    d->AddSubordinate(e); //Jimmy works for Bob

    //Jerry shows his happiness and asks everyone else to do the same
    c->ShowHappiness();
}
