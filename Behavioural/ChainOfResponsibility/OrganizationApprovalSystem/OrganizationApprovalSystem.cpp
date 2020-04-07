#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Purchase {
private:
  int poNumber_;
  double amount_;
  string purpose_;

public:
  Purchase(int poNumber, double amount, string purpose)
    : poNumber_(poNumber) , amount_(amount) , purpose_(purpose)
  { }

  int getPONumber() { return poNumber_; }

  void getPONumber(int poNumber) { poNumber_ = poNumber; }

  double Amount() { return amount_; }
  
  void Amount(double amount) { amount_ = amount; }

  string Purpose() { return purpose_; }

  void Purpose(string purpose) { purpose_ = purpose; }
};

class Approver {
protected:
  Approver* successor_;

public:
  void SetSuccessor(Approver* successor) {
    successor_ = successor;
  }

  virtual void ProcessRequest(Purchase* purchase) = 0;
};

class Director : public Approver {
public:
  virtual void ProcessRequest(Purchase* purchase) {
    if(purchase->Amount() < 1000.0) {
      cout << "Director approved request # " << purchase->getPONumber() << endl;
    } else if(successor_ != 0) {
      successor_->ProcessRequest(purchase);
    }
  }
};

class VicePresident : public Approver {
public:
  virtual void ProcessRequest(Purchase* purchase) {
    if(purchase->Amount() < 25000.0) {
      cout << "VicePresident approved request # " << purchase->getPONumber() << endl;
    } else if(successor_ != 0) {
      successor_->ProcessRequest(purchase);
    }
  }
};

class President : public Approver {
public:
  virtual void ProcessRequest(Purchase* purchase) {
    if(purchase->Amount() < 100000.0) {
      cout << "President approved request # " << purchase->getPONumber() << endl;
    } else {
      cout << "Request # " << purchase->getPONumber() << " requires an executive meeting!" << endl;
    }
  }
};

int main() {
  Approver *larry = new Director();
  Approver *sam = new VicePresident();
  Approver *tammy = new President();

  //The following chain can be set differently for each users in an organization
  larry->SetSuccessor(sam);
  sam->SetSuccessor(tammy);

  Purchase *p = new Purchase(2034, 350.00, "Assets");
  larry->ProcessRequest(p);

  delete p;
  p = new Purchase(2035, 32590.10, "Project X");
  larry->ProcessRequest(p);

  delete p;
  p = new Purchase(2036, 122100.00, "Project Y");
  larry->ProcessRequest(p);
  
  return 0;
}
