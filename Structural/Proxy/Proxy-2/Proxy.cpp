#include <iostream>
using namespace std;
class Subject
{
    protected:
        Subject(){};
    public:
        virtual ~Subject( ){};
        virtual void Request() = 0;
};

class ConcreteSubject:public Subject
{
    public:
        ConcreteSubject(){};
        ~ConcreteSubject(){};

        void Request()
        {
            cout<< "Concrete Subject......request .." <<	endl;
        }
};

class Proxy // Non standard Proxy here, in main Concrete subject is passed as proxy argument
{
    private:
        Subject* m_subject;
        Proxy (){};
    public:
        Proxy (Subject* sub)
        {
            m_subject = sub;
        }

        ~Proxy ( )
        {
            delete m_subject;
        }

        void Proxy ::Request()
        {
            cout<<"Proxy request...."<<endl;
            m_subject->Request();
        }
};

int main(int argc,char* argv[] )
{
    Subject* sub = new ConcreteSubject();
    Proxy *p = new Proxy (sub);
    p->Request();
    system("pause");
    return 0;
}
