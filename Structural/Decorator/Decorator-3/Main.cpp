#include <string>
#include <iostream>

class IEmployee
{
    public:
        virtual std::string Join( void ) = 0;
        virtual std::string Terminate( void ) = 0;
        virtual std::string PerformJob( void ) = 0;
};

class Employee : public IEmployee
{
    public:
        std::string Name;

        Employee(std::string Name)
        {
            this->Name = Name;
        }
        std::string Join( void )
        {
            return Name + " joined the company..";
        }

        std::string Terminate( void )
        {
            return Name + " left the company..";
        }
        std::string PerformJob( void )// Any Employee Basic Job
        {
            return Name + " doing basic stuff..";
        }

};

class Role: public IEmployee
{
    public:
        IEmployee* m_employee;
        Role(IEmployee* Employee):m_employee(Employee){}

        //virtual std::string PerformJob( void ) = 0;// If PerformJob not implemented then also it is abstract

        std::string Join( void )// Every employee can join and Terminate this Role
        {
            return m_employee->Join();
        }

        std::string Terminate( void )
        {
            return m_employee->Terminate();
        }
};

class Engineer : public Role
{
    public:
        Engineer(IEmployee* Employee):Role(Employee){}

        std::string PerformJob( void )//Engineer specific job
        {
            return m_employee->PerformJob() + " and Coding";
        }
};

class TeamLead : public Role
{
    public:
        TeamLead(IEmployee* Employee):Role(Employee){}
        std::string PerformJob( void )//Team Lead specific job
        {
            return m_employee->PerformJob() + " and Task Management";
        }
};

class Manager : public Role
{
    public:
        Manager(IEmployee* Employee):Role(Employee){}
        std::string PerformJob( void )//Manager specific job
        {
            return m_employee->PerformJob() + " and People management";
        }
};

int main()
{
    IEmployee* employee1 = new Employee("George");
    IEmployee* employee2 = new Employee("John");
    IEmployee* employee3 = new Employee("Thomas");
    std::cout << employee1->Join() << std::endl;
    std::cout << employee2->Join() << std::endl;
    std::cout << employee3->Join() << std::endl;

    Engineer* engineer = new Engineer(employee1);
    std::cout << engineer->PerformJob() << std::endl;

    TeamLead* lead = new TeamLead(employee2);
    std::cout << lead->PerformJob() << std::endl;

    Manager* manager = new Manager(new TeamLead(employee3));
    std::cout << manager->PerformJob() << std::endl;

    std::cout << engineer->Terminate() << std::endl;
    std::cout << lead->Terminate() << std::endl;
    std::cout << manager->Terminate() << std::endl;
}
