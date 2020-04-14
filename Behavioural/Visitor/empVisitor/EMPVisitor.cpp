#include <iostream>
using namespace std;

class Employee;
class ManagerEmployee;
class CommonEmployee;

class VisitorBase {
    public:
	VisitorBase(){}
	virtual ~VisitorBase(){}

	virtual void Visit(Employee *yee) = 0;
	virtual void Visit(ManagerEmployee *employee) = 0;
	virtual void Visit(CommonEmployee *employee) = 0;
};

class Employee {
    public:
	Employee(){}
	virtual ~Employee(){}
	virtual std::string getEMPInfo() = 0;
	virtual void Accept(VisitorBase *visitor) {
	    visitor->Visit(this); }
};


class ManagerEmployee : public Employee {
    std::string m_name;
    std::string m_job;
    ManagerEmployee(){} 
    public:
    ManagerEmployee(std::string name, std::string role):m_name(name),m_job(role){} 
    std::string getEMPInfo() {
	return m_name + " is " + m_job; }
    void Accept(VisitorBase *visitor) {
	visitor->Visit(this); }
};

class CommonEmployee : public Employee {
    std::string m_name;
    std::string m_job;
    CommonEmployee(){}
    public:
    CommonEmployee(std::string name, std::string role):m_name(name),m_job(role){} 
    std::string getEMPInfo() {
	return m_name + " is " + m_job; }
    void Accept(VisitorBase *visitor) {
	visitor->Visit(this); }
};

class HRVisitor : public VisitorBase {
    public:
	HRVisitor(){}
	~HRVisitor(){}
	void Visit(Employee *employee) {
	    std::string info = employee->getEMPInfo();
	    printf("do with base employee->%s\n",info.c_str());
	}
	void Visit(ManagerEmployee *employee) {
	    std::string info = employee->getEMPInfo();
	    printf("do sth diffirent with base manager employee->%s\n",info.c_str());
	}
	void Visit(CommonEmployee *employee) {
	    std::string info = employee->getEMPInfo();
	    printf("do sth diffirent with base common employee->%s\n",info.c_str());
	}
};

int main(int argc, const char * argv[])
{
    ManagerEmployee *manager = new ManagerEmployee("Roy","Leader");

    CommonEmployee *common = new CommonEmployee("Micle","Coder");

    HRVisitor *visitor = new HRVisitor;

    manager->Accept(visitor);
    common->Accept(visitor);

    return 0;
}
