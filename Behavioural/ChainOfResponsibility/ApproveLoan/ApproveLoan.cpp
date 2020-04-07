#include <iostream>

std::string loanStateArray[] = { "New", "WaitingApproval", "ApprovedLoan", "RejectedLoan"};
enum State { New, WaitingApproval, ApprovedLoan, RejectedLoan };

class LoanRequest
{    
public:
    int m_amount;// should be privete, but made public for ease
    State m_state;// should be privete, but made public for ease    
    void setLoanAmount( int amount ){ m_amount = amount; }
    State getLoanState() { return m_state;} 
    void setLoanState( State state ) { m_state = state;} 
};

class BaseRequestHandler
{
protected:
    virtual void Execute(LoanRequest& request) = 0;

public:
    BaseRequestHandler* Successor;// should be privete, but made public for ease
    BaseRequestHandler():Successor(NULL) // Manager Handler successor is NULL
    {}
    void ExecuteRequest(LoanRequest& request)
    {
        Execute(request); // first handle your Execute and pass it to succesor, let everybody review the request
        if (Successor != NULL) // Manager Handler successor is NULL, so every request goes till manager, irrespective of it is passed or rejected
            Successor->ExecuteRequest(request);
    } 
};

class FirstApproverRequestHandler: public BaseRequestHandler
{
protected:
    void Execute(LoanRequest& request)
    {
        if( request.getLoanState() != ApprovedLoan )//else can be return also but let it print Execute : Request handler message
        {
            if( request.m_amount <= 100000 )
            {
                std::cout << request.m_amount << "INR loan approved by First Approver" << std::endl;
                // based on approval criteria approve loan
                request.setLoanState( ApprovedLoan );	
            }
            else
            {
                request.setLoanState( WaitingApproval );
            }    
        }
        std::cout << "Execute : FirstApproverRequestHandler" << std::endl;
    }
};

class SecondApproverRequestHandler: public BaseRequestHandler
{
protected:
    void Execute(LoanRequest& request)
    {
        if( request.getLoanState() != ApprovedLoan )//else can be return also but let it print Execute : Request handler message
        {
            if( request.m_amount <= 1000000 )
            {
                std::cout << request.m_amount << "INR loan approved by Second Approver" << std::endl;
                // based on approval criteria approve loan
                request.setLoanState( ApprovedLoan );
            }
            else
            {
                request.setLoanState( WaitingApproval );
            }    
        }
        std::cout << "Execute : SecondApproverRequestHandler" << std::endl;
    }
};

class ManagerApproverRequestHandler: public BaseRequestHandler
{
protected:
    void Execute(LoanRequest& request)
    {
        if( request.getLoanState() != ApprovedLoan )//else can be return also but let it print Execute : Request handler message
        {
            if( request.m_amount <= 10000000 && request.m_amount < 100000000 )// between carore and 10 carore
            {
                std::cout << request.m_amount << "INR loan approved by Manager" << std::endl;
                // based on approval criteria approve the loan
                request.setLoanState( ApprovedLoan );
            }
            else
            {
                request.setLoanState( RejectedLoan );
            }    
        }
        std::cout << "Execute : ManagerApproverRequestHandler"<< std::endl;
    }
};

int main()
{
    BaseRequestHandler* handler = new FirstApproverRequestHandler();
    BaseRequestHandler* handler1 = new SecondApproverRequestHandler();
    BaseRequestHandler* handler2 = new ManagerApproverRequestHandler();

    // setup chain of responsibility
    handler->Successor = handler1;
    handler1->Successor = handler2;

    // Loan request object
    LoanRequest request;
    request.setLoanAmount(100000000); // 1 carore
    request.setLoanState( New );

    // handler -> request executer
    handler->ExecuteRequest(request);        
    std::cout << "loan Status is: " << loanStateArray[request.getLoanState()] << std::endl;
}