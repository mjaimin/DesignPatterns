/*
 * Adopted from http://www.cppblog.com/converse/archive/2006/07/28/10663.html
 */

#include <iostream>
using namespace std;

class IHandler {
public:
	IHandler( IHandler* successor = NULL )
		:m_successor( successor ) {
	}

	virtual void handleRequest() = 0;
protected:
	IHandler* m_successor;
};

class ConcreteHandler1 : public IHandler {
public:
	ConcreteHandler1( IHandler* successor = NULL )	
		:IHandler( successor ) {
	}

	virtual void handleRequest() {
		if ( NULL != m_successor ) {
			m_successor->handleRequest();
		} else {
			cout << "handleRequest by ConcreteHandler1" << endl;
		}
	}
};

class ConcreteHandler2 : public IHandler {
public:
	ConcreteHandler2( IHandler* successor = NULL )
		:IHandler( successor ) {
		}
	virtual void handleRequest() {
		if ( NULL != m_successor ) {
			m_successor->handleRequest();
		} else {
			cout << "handleRequest by ConcreteHandler2" << endl;
		}
	}
};

int main() {

	IHandler* handler1 = new ConcreteHandler1();
	IHandler* handler2 = new ConcreteHandler2( handler1 );

	handler2->handleRequest();


	return 0;
}