#include <iostream>
using namespace std;

class Context;

class State {
    public:
        virtual void handle(Context *context) = 0;
};

class Context {
    private:
        State *m_state;
    public:
        Context(State *state) : m_state(state) { }
        void request()
        {
            m_state->handle(this);
        }

        void changeState(State *state)
        {
            m_state = state;
        }
};


class ConcreteStateA : public State {
    public:
        void handle(Context *context);
};


class ConcreteStateB : public State {
    public:
        void handle(Context *context);
};

void ConcreteStateA::handle(Context *context)
{
    cout << "Handle by ConcreteStateA" << endl;
    context->changeState(new ConcreteStateB());
}

void ConcreteStateB::handle(Context *context)
{
    cout << "Handle by ConcreteStateB" << endl;
    context->changeState(new ConcreteStateA());
}

int main()
{
    State   *state   = new ConcreteStateA();
    Context *context = new Context(state);

    context->request();
    context->request();
    context->request();
    context->request();
    context->request();
}
