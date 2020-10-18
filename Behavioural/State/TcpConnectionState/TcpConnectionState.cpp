#include <iostream>
#include <string>
#include <vector>
using namespace std;
class TCPconnection;

class State {
    public:
        virtual void Open() = 0;
        virtual void Close() = 0;
        virtual void Acknowledge() = 0;
};

class TCPopen : public State {
    TCPconnection *tcp;
    public:
    TCPopen(TCPconnection *tcp): tcp(tcp) { }

    void Open() { cout << "The Tcp is already opened." << endl; }
    void Acknowledge();
    void Close();
};

class TCPclose : public State {
    TCPconnection *tcp;
    public:
    TCPclose(TCPconnection *tcp): tcp(tcp) { }

    void Acknowledge() { cout << "The Tcp is not opened yet." << endl; }
    void Close() { cout << "The Tcp is already close." << endl; }
    void Open();
};

class TCPacknowledge : public State
{
    TCPconnection *tcp;
    public:
    TCPacknowledge(TCPconnection *tcp): tcp(tcp) { }

    void Open() { cout << "The Tcp is already open" << endl; }
    void Acknowledge() { cout << "The Tcp is already acknowleged." << endl; }
    void Close();
};

class TCPconnection
{
    State *currentState;
    State *stateOpened;
    State *stateClosed;
    State *stateAcknowledged;
    public:
    TCPconnection() {
        stateOpened = new TCPopen(this);
        stateClosed = new TCPclose(this);
        stateAcknowledged = new TCPacknowledge(this);
        currentState = stateClosed;
    }

    void Open() { currentState->Open(); }
    void Close() { currentState->Close(); }
    void Acknowledge() { currentState->Acknowledge(); }
    void changeCurrentState(State *state) { this->currentState= state; }

    State *getTCPclose() { return stateClosed; }
    State *getTCPopen() { return stateOpened; }
    State *getTCPacknowledge() { return stateAcknowledged; }
};

// because the classes have cross-reference
// so the following methods MUST be defined after TCPconnection
void TCPopen::Acknowledge() {
    cout << "The Tcp is acknowleged." << endl;
    tcp->changeCurrentState(tcp->getTCPacknowledge());
}

void TCPopen::Close() {
    cout << "Yeah. The Tcp is close." << endl;
    tcp->changeCurrentState(tcp->getTCPclose());
}

void TCPclose::Open() {
    cout << "The Tcp is open" << endl;
    tcp->changeCurrentState(tcp->getTCPopen());
}

void TCPacknowledge::Close() {
    cout << "The Tcp is closed." << endl;
    tcp->changeCurrentState(tcp->getTCPclose());
}
int main()
{
    TCPconnection tcp;

    tcp.Open();
    tcp.Open();
    tcp.Acknowledge();
    tcp.Close();

    tcp.Acknowledge(); // will not acknowleged, since the tcp is not open
    return 0;
}
