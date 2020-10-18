#include <iostream>
class State;
class Context
{
    private:
        State* current;

    public:
        void setState(State* state);
        void Request();
};

class State {
    public:
        virtual void goNext(Context* ) = 0;
};

class StateOne: public State {
    public:
        void goNext(Context*);
};

class StateTwo: public State {
    public:
        void goNext(Context*);
};

class StateThree : public State {
    public:
        void goNext(Context*);
};


void StateOne::goNext(Context* context) {
    std::cout<<"Current State: StateOne" << std::endl;
    context->setState(new StateTwo());
    std::cout<<"Next State: StateTwo\n" << std::endl;
}
void StateTwo::goNext(Context* context) {
    std::cout<<"Current State: StateTwo" << std::endl;
    context->setState(new StateThree());
    std::cout<<"Next State: StateThree\n" << std::endl;
}
void StateThree::goNext(Context* context) {
    std::cout<<"Current State: StateThree" << std::endl;
    context->setState(new StateOne());
    std::cout<<"Next State: StateOne\n" << std::endl;
}


void Context::setState(State* state) {
    current = state;
}

void Context::Request() {
    current->goNext(this);
}

int main()
{
    Context* c = new Context();
    c->setState(new StateOne());
    c->Request();
    c->Request();
    c->Request();
    c->Request();
    c->Request();
}
