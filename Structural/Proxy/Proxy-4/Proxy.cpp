#include <iostream>
#include <string>

class InternetAccess 
{
public:
    virtual void grantInternetAccess() = 0;
};

class RealInternetAccess: public InternetAccess 
{
private: 
    std::string m_empName;

public: 
    RealInternetAccess(std::string strEmployeeName): m_empName(strEmployeeName){}
    void grantInternetAccess() {
        std::cout << "Internet Access granted for employee: "
            << m_empName << std::endl;
    }
};

class ProxyInternetAccess: public InternetAccess 
{
private:
    std::string m_empName;
    RealInternetAccess* objRealIA;

public: 
    ProxyInternetAccess(std::string strEmployeeName):m_empName(strEmployeeName), objRealIA(NULL){}

    void grantInternetAccess() 
    {
        if (getRole(m_empName) > 5) 
        {
            objRealIA = new RealInternetAccess(m_empName);
            objRealIA->grantInternetAccess();
        } else 
        {
            std::cout << "No Internet access granted. Your job level is below 5" << std::endl;
        }
    }

    int getRole(std::string emplName) 
    {
        // Check role database based on Name and return job level
        return 7;
    }
};

int main()
{
    InternetAccess* ia = new ProxyInternetAccess("Idiotechie");
    ia->grantInternetAccess();
}