#include <iostream>
#include <stdio.h>
class Account
{
    int id;
    public:
    Account(int AccountId)
    {
        id = AccountId;
    }

    int getId() { return id; }

    virtual void Withdraw(int accountId, int amount)
    {
        printf("In base withdraw\n");
    }
};

class SavingAccount : public Account
{
    public:
        SavingAccount(int savingAccountId):Account(savingAccountId) {}

        void Withdraw(int accountId, int amount)
        {
            printf("In SavingAccount withdraw\n");
            Account::Withdraw(accountId, amount);
        }
};

class Bank
{
    public:
        virtual void Withdraw(Account* acc, int amount)
        {
            acc->Withdraw(acc->getId(), amount);
        }
};



class CheckingAccount : public Account
{
    public:
        CheckingAccount(int checkingAccountId):Account(checkingAccountId)
    {
    }

        void Withdraw(int accountId, int amount)
        {
            printf("In CheckingAccount withdraw\n");
            Account::Withdraw(accountId, amount);
        }
};

int main()
{
    Bank* bank = new Bank();
    Account* acc = new Account(1);
    bank->Withdraw(acc, 100);

    Account* saving = new SavingAccount(2);
    bank->Withdraw(saving, 100);
    //As LSP states, the program should be able to use the objects of derived class without breaking any behavior of base class. So in this code, I am passing a SavingAccount instance to Withdraw method, which executes the function defined in Account class. So we are adhering to LSP pattern here.
}
