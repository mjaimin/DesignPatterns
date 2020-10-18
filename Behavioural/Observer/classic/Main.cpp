/*
 * Adopted from http://www.cppblog.com/converse/archive/2006/08/05/10858.html
 */

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class Observer;

// Subject Interface (Observable)
class Subject {
    protected:
        int              State;
        list<Observer *> List;

    public:
        Subject() : State(-1) { }

        void notify();

        void attach(Observer *observer)
        {
            cout << "attach an Observer" << endl;
            List.push_back(observer);
        }

        void detach(Observer *observer)
        {
            list<Observer *>::iterator iter;
            iter = find(List.begin(), List.end(), observer);

            if (List.end() != iter)
            {
                List.erase(iter);
            }
            cout << "detach and Observer" << endl;
        }

        virtual void setState(int state)
        {
            cout << "setState by subject" << endl;
            State = state;
        }

        virtual int getState()
        {
            cout << "getState by subject" << endl;
            return State;
        }
};

class Observer {
    public:
        virtual void update(Subject *subject) = 0;

    protected:
        int State;
};

class ConcreteSubject : public Subject {
    public:
        virtual void setState(int state)
        {
            cout << "setState by ConcreteSubject" << endl;
            State = state;
        }

        virtual int getState()
        {
            cout << "getState by ConcreteSubject" << endl;
            return State;
        }
};

class ConcreteObserver : public Observer {
    public:
        virtual void update(Subject *subject)
        {
            if (NULL == subject)
            {
                return;
            }
            State = subject->getState();
            cout << "the ObserverState is " << State << endl;
        }
};

void Subject::notify()
{
    cout << "notify observer's state" << endl;

    list<Observer *>::iterator iter1, iter2;
    for (iter1 = List.begin(), iter2 = List.end();
            iter1 != iter2;
            ++iter1)
    {
        (*iter1)->update(this);
    }
}


int main()
{
    Observer *observer1 = new ConcreteObserver();
    Observer *observer2 = new ConcreteObserver();

    Subject *subject = new ConcreteSubject();

    subject->attach(observer1);
    subject->attach(observer2);

    subject->setState(4);
    subject->notify();

    subject->detach(observer1);
    subject->setState(10);
    subject->notify();

    return 0;
}
