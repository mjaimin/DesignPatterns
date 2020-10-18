#include <iostream>
using namespace std;

class Command {
    public:
        virtual void execute() = 0;
};

//Receiver
class Receiver {
    public:
        virtual void switchOn() = 0;
        virtual void switchOff() = 0;
};

class Light : public Receiver {
    public:
        void switchOn() {
            m_on = true;
            cout << "Light is switched on" << endl;
        }

        void switchOff() {
            m_on = false;
            cout << "Light is switched off" << endl;
        }
    private:
        bool m_on;
};

class Television : public Receiver {
    public:
        void switchOn() {
            m_on = true;
            cout << "Television is switched on" << endl;
        }

        void switchOff() {
            m_on = false;
            cout << "Television is switched off" << endl;
        }

    private:
        bool m_on;
};

//ConcreteCommand1
class OnCommand : public Command {
    public:
        OnCommand(Receiver* receiver)
            :m_receiver(receiver) {
            }

        void execute() {
            m_receiver->switchOn();
        }

    private:
        Receiver* m_receiver;
};


//ConcreteCommand2
class OffCommand : public Command {
    public:
        OffCommand(Receiver* receiver)
            :m_receiver(receiver) {
            }

        void execute() {
            m_receiver->switchOff();
        }
    private:
        Receiver* m_receiver;
};

//Invoker
class RemoteControl {
    public:
        void setCommand(Command* command) {
            m_command = command;
        }
        void pressButton() {
            m_command->execute();
        }

    private:
        Command* m_command;
};




int main() {
    RemoteControl* control = new RemoteControl();

    Receiver* light = new Light();

    Command* lightsOn = new OnCommand( light );
    Command* lightsOff = new OffCommand( light );

    //switch on light
    control->setCommand( lightsOn );
    control->pressButton();

    //switch off light
    control->setCommand( lightsOff );
    control->pressButton();

    Receiver* tv = new Television();

    Command* tvOn = new OnCommand( tv );
    Command* tvOff = new OffCommand( tv );

    //switch on TV
    control->setCommand( tvOn );
    control->pressButton();

    //switch off TV
    control->setCommand( tvOff );
    control->pressButton();


    return 0;
}
