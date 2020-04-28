#include <iostream>
#include <stdio.h>

class StateContext;

class State {
    public:
	virtual void grantPermission(StateContext*  context) = 0;
	virtual void requestPermission(StateContext*  context) = 0;
	virtual std::string getStatus() = 0;
};

class StateContext {
    private:
	State* accepted;
	State* requested;
	State* granted;
	State* state;
    public:
	StateContext(); 
	void acceptApplication();
	void requestPermission();
	void grantPermission();
	std::string getStatus();
	void setState(State* s);
	State* getAcceptedState();
	State* getGrantedState();
	State* getRequestedState();
};

class AcceptedState: public State {

    public:
	std::string getStatus() {
	    // TODO Auto-generated method stub
	    return "Request received";
	}

	void grantPermission(StateContext*  context) {
	    // TODO Auto-generated method stub
	    std::cout << "Invalid state" << std::endl;
	}

	void requestPermission(StateContext*  context) {
	    // TODO Auto-generated method stub
	    std::cout << "Requesting Permission" << std::endl;
	    context->setState(context->getRequestedState());
	}
};

class GrantedState: public State{
    public:
	std::string getStatus() {
	    // TODO Auto-generated method stub
	    return "Request received";
	}

	void grantPermission(StateContext*  context) {
	    // TODO Auto-generated method stub
	    std::cout << "Invalid State" << std::endl;
	}

	void requestPermission(StateContext*  context) {
	    // TODO Auto-generated method stub
	    std::cout << "Invalid State" << std::endl;
	}
};

class RequestedState: public State {
    public:  
	std::string getStatus() {
	    // TODO Auto-generated method stub
	    std::cout << "Requested Permission" << std::endl;
	    return "";
	}

	void grantPermission(StateContext*  context) {
	    // TODO Auto-generated method stub
	    std::cout << "Granting Permission" << std::endl;
	    context->setState(context->getGrantedState());
	}

	void requestPermission(StateContext*  context) {
	    // TODO Auto-generated method stub
	    std::cout << "Permission already requested" << std::endl;
	}
};

StateContext::StateContext() {
    // TODO Auto-generated constructor stub
    accepted=new AcceptedState();
    requested=new RequestedState();
    granted=new GrantedState();
}
void StateContext::acceptApplication(){
    state=accepted;
}
void StateContext::requestPermission(){
    state->requestPermission(this);
}
void StateContext::grantPermission(){
    state->grantPermission(this);
}
std::string StateContext::getStatus(){
    return state->getStatus();
}
void StateContext::setState(State* s){
    state = s;
}
State* StateContext::getAcceptedState(){
    return accepted;
}
State* StateContext::getGrantedState(){
    return granted;
}
State* StateContext::getRequestedState(){
    return requested;
}


int main(){
    StateContext* ctx=new StateContext();
    ctx->acceptApplication();
    ctx->requestPermission();
    ctx->grantPermission();
    std::cout << ctx->getStatus() << std::endl;		
}
