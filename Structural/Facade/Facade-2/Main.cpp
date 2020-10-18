#include <iostream>
#include <string>

class Customer
{
    private:
        Customer(){};
    public:
        std::string Name;

        Customer(std::string name)
        {
            Name = name;
            // and other details
        }
};

class BankSubsystem
{
    public:
        bool IsValidCustomer(Customer& cust)
        {
            std::cout << "Check " << cust.Name << " is valid" << std::endl;
            return true;
        }
};

class LoanSubsystem
{
    public:
        bool HasNoBadLoan(Customer& cust)
        {
            std::cout << "Check " << cust.Name << " for bad loans" << std::endl;
            return true;
        }
};

class CreditSubsystem
{
    public:
        bool HasGoodCredit(Customer& customer)
        {
            std::cout << "Check " << customer.Name << " for good credit" << std::endl;
            return true;
        }
};

class MortgageFacade
{
    private:
        BankSubsystem*		bank;
        LoanSubsystem*		loan;
        CreditSubsystem*	credit;
    public:
        MortgageFacade()
        {
            bank	= new BankSubsystem;
            loan	= new LoanSubsystem;
            credit	= new CreditSubsystem;
        }

        bool IsEligible(Customer& cust)
        {
            bool isEligible = true;
            if (!bank->IsValidCustomer(cust) )
            {
                isEligible = false;
            }
            else if( !loan->HasNoBadLoan(cust) )
            {
                isEligible = false;
            }
            else if( !credit->HasGoodCredit(cust) )
            {
                isEligible = false;
            }
            return isEligible;
        }
};

int main(){
    Customer customer("Jonathan");
    MortgageFacade* mortgageLoanObj = new MortgageFacade;
    bool validity = mortgageLoanObj->IsEligible(customer);
    if ( validity )
    {
        std::cout << "First level loan check is cleared for " << customer.Name << std::endl;
    }
    else
    {
        std::cout << "First level loan check not cleared for " << customer.Name << std::endl;
    }
    while(1){;}
}
