#include <iostream>

class Subject// Interface
{
public:
    Subject(){}
    virtual ~Subject(){}
    virtual void Request() = 0;
};

class RealSubject: public Subject
{
public:

    RealSubject()
    {
        std::cout << "Constructing a RealSubject\n";
    }
    virtual ~RealSubject(){}
    virtual void Request()
    {
        std::cout << "Request By RealSubject\n";
    }
};


class Proxy	: public Subject
{
private:
    RealSubject* m_pRealSubject;

public:
    Proxy(): m_pRealSubject(NULL)
    {
        std::cout << "Constructing a Proxy\n";
    }

    virtual ~Proxy()
    {
        delete m_pRealSubject;
        m_pRealSubject = NULL;
    }
    virtual void Request()
    {
        if (NULL == m_pRealSubject)
        {
            std::cout << "Request By Proxy\n";
            m_pRealSubject = new RealSubject();
        }
        m_pRealSubject->Request();
    }
};
int main()
{
	Subject* pProxy = new Proxy();
	pProxy->Request();
	delete pProxy;
	return 0;
}
