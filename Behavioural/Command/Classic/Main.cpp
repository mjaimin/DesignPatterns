#include <iostream>
using namespace std;

class Command {
    public:
        virtual void execute() = 0;
};

class Receiver {
    public:
        void action() {
            cout << "Receiver Action" << endl;
        }
};

class Invoker {
    public:
        Invoker(Command* command)
            :m_command(command) {
            }
        void invoke() {
            m_command->execute();
        }
    private:
        Command* m_command;
};

class ConcreteCommand : public Command {
    public:
        ConcreteCommand(Receiver* receiver)
            :_receiver(receiver) {

            }

        virtual void execute() {
            _receiver->action();

            cout << "Execute by ConcreteCommand" << endl;
        }
    private:
        Receiver* _receiver;
};


int main (int argc, char const* argv[]) {

    Receiver* receiver = new Receiver();
    Command* command = new ConcreteCommand( receiver );
    Invoker* invoker = new Invoker( command );

    invoker->invoke();


    return 0;
}
