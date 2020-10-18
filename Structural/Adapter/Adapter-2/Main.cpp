#include <iostream>
#include <string>
#include <list>
class IEmployee
{
    public:
        virtual void ShowHappiness() = 0;
};

class Employee : public IEmployee
{
    private:
        std::string name;
        Employee(){};
    public:
        Employee( std::string name )
        {
            this->name = name;
        }
        void ShowHappiness()
        {
            std::cout << "Employee " << this->name << " showed Happiness" << std::endl;
        }
};

class Consultant
{
    protected:
        std::string name;
        Consultant(){}
    public:
        Consultant( std::string name )
        {
            this->name = name;
        }
        //incompatible Interface
        void ShowSmile()
        {
            std::cout << "Consultant " << this->name << " showed Smile" << std::endl;
        }

};

class EmployeeAdapter : public Consultant, public IEmployee
{
    public:
        EmployeeAdapter(std::string name)
        {
            this->name = name;
        }
        void ShowHappiness()
        {
            ShowSmile();
        }
};

int main()
{
    std::list<IEmployee*> employeeList;
    employeeList.push_back( new Employee( std::string("Tom") ) );
    employeeList.push_back( new Employee( std::string("Jerry") ) );
    employeeList.push_back( new EmployeeAdapter( std::string("Pluto") ) );

    for( std::list<IEmployee*>::iterator itr = employeeList.begin(); itr != employeeList.end(); ++itr )
    {
        (*itr)->ShowHappiness();
    }
}
