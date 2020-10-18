#include <iostream>
using namespace std;

class Sun;

class State {
    public:
        virtual void nextState(Sun *sun) = 0;
        virtual const char *toString()   = 0;
};

class Dawn : public State {
    public:
        virtual void nextState(Sun *sun);
        virtual const char *toString() { return "Dawn"; }
};

class Morning : public State {
    public:
        virtual void nextState(Sun *sun);
        virtual const char *toString() { return "Morning"; }
};

class MidDay : public State {
    public:
        virtual void nextState(Sun *sun);
        virtual const char *toString() { return "MidDay"; }
};

class Evening : public State {
    public:
        virtual void nextState(Sun *sun);
        virtual const char *toString() { return "Evening"; }
};

class Night : public State {
    public:
        virtual void nextState(Sun *sun);
        virtual const char *toString() { return "Night"; }
};


class Sun {
    private:
        State *m_state;
    public:
        Sun(State *state) : m_state(state) { }
        void afterSixHours() { m_state->nextState(this); }
        void changeState(State *state) { m_state = state; }
        const char *getState() { return m_state->toString(); }
};

void Dawn::nextState(Sun *sun) 		{ sun->changeState(new Morning()); }
void Morning::nextState(Sun *sun) 	{ sun->changeState(new MidDay()); }
void MidDay::nextState(Sun *sun) 	{ sun->changeState(new Evening()); }
void Evening::nextState(Sun *sun) 	{ sun->changeState(new Night()); }
void Night::nextState(Sun *sun) 	{ sun->changeState(new Dawn()); }


int main()
{
    Sun *sun = new Sun(new Dawn());

    sun->afterSixHours(); std::cout << sun->getState() << std::endl;
    sun->afterSixHours(); std::cout << sun->getState() << std::endl;
    sun->afterSixHours(); std::cout << sun->getState() << std::endl;
    sun->afterSixHours(); std::cout << sun->getState() << std::endl;
    sun->afterSixHours(); std::cout << sun->getState() << std::endl;

    return 0;
}
