#include <iostream>
#include <string>
class Memento // The 'Memento' class
{
    private:

    public:
        std::string Name;
        std::string Phone;
        double      Budget;
        Memento(std::string name, std::string phone, double budget) : Name(name), Phone(phone), Budget(budget) { }
};

class SalesProspect /// The 'Originator' class
{
    private:
        double      Budget;
        std::string Name;
        std::string Phone;
    public:
        void setName(std::string name) { Name = name; }
        void setPhone(std::string phone) { Phone = phone; }
        void setBudget(double budget) { Budget = budget; }

        SalesProspect(std::string name, std::string phone, double budget) : Name(name), Phone(phone), Budget(budget) { }
        Memento *CreateMemento()
        {
            return new Memento(Name, Phone, Budget);
        }

        // Restores memento
        void RestoreMemento(Memento *memento)
        {
            Name   = memento->Name;
            Phone  = memento->Phone;
            Budget = memento->Budget;
        }

        void printSalesProspect()
        {
            std::cout << Name << std::endl << Phone << std::endl << Budget << std::endl;
        }
};

class ProspectMemory  // The 'Caretaker' class
{
    private:
        Memento *memento;
    public:
        void saveState(SalesProspect *originator)
        {
            memento = originator->CreateMemento();
        }

        void restoreState(SalesProspect *restore)
        {
            restore->RestoreMemento(memento);
        }
};
int main()
{
    SalesProspect *tmpObj = new SalesProspect("Noel van Halen", "(412) 256-0990", 25000.0);
    // Store internal state
    ProspectMemory *m = new ProspectMemory();

    m->saveState(tmpObj);
    // Continue changing originator
    tmpObj->printSalesProspect();
    tmpObj->setName("Leo Welch");
    tmpObj->setPhone("(310) 209-7111");
    tmpObj->setBudget(1000000.0);
    tmpObj->printSalesProspect();
    // Restore saved state
    m->restoreState(tmpObj);
    tmpObj->printSalesProspect();
}
