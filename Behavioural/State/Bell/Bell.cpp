#include <iostream>
class BellState {
    public:
        virtual void Ring() = 0;
};

class BellRingingState : public BellState {
    public:
        void Ring() { printf("Bell is ringing...\n"); }
};

class BellSilentState : public BellState {
    public:
        void Ring() { printf("Bell isn't ringing...\n"); }
};

class Bell {
    private:
        BellState* currentState;
    public:
        Bell() { currentState = new BellRingingState(); }
        void setState(BellState* state) { currentState = state; }
        void alert() { currentState->Ring(); }
};

int main()
{
    Bell* stateContext = new Bell();
    stateContext->alert();
    stateContext->alert();
    stateContext->setState(new BellSilentState());
    stateContext->alert();
    stateContext->alert();
    stateContext->alert();
}
