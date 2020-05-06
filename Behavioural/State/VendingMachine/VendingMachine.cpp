#include <iostream>
class VendingMachine;
class VendingMachineState {
    public: 
	virtual void ChangeVendingState(VendingMachine* context) = 0;
	virtual void GetProduct(int amount, VendingMachine* context) = 0;
};

class VendingMachine {
    private:
	VendingMachineState* current;
	int CostOfProduct;
    public: 
	void setState(VendingMachineState* state) {
	    current = state;
	}
	void BuyProduct(int amount) {
	    CostOfProduct = amount;
	    current->GetProduct(amount, this);
	}
	void TakeProduct() {
	    current->GetProduct(CostOfProduct, this);
	}
};

class VendingDepositeState: public VendingMachineState {
    public:
	void ChangeVendingState(VendingMachine* context);
	void GetProduct(int amount, VendingMachine* context);
};

class VendingStockState: public VendingMachineState {
    public:
	void ChangeVendingState(VendingMachine* context);
	void GetProduct(int amount, VendingMachine* context);
};

void VendingDepositeState::ChangeVendingState(VendingMachine* context) {
    context->setState(new VendingStockState());
}

void VendingDepositeState::GetProduct(int amount, VendingMachine* context) {
    std::cout << "Thrown into the machine: " <<  amount << std::endl;

    if (amount==5) {
	std::cout<<"Payment accepted"<< std::endl;
	ChangeVendingState(context);
    }
    else if(amount>=5) {
	int returnMoney = amount - 5;
	std::cout << "Payment accepted, return the rest of money: " << returnMoney<< std::endl<< std::endl;
	ChangeVendingState(context);
    }
    else {
	printf("Not enough money\n\n");
    }
}

void VendingStockState::ChangeVendingState(VendingMachine* context) {
    context->setState(new VendingDepositeState());
}

void VendingStockState::GetProduct(int amount, VendingMachine* context) {
    std::cout << "Money received, amount: " << amount << " , the delivered product value: 5\n";
    ChangeVendingState(context);
}

int main()
{
    std::cout << "Machine Dispaches single product, Product Value : 5" << std::endl;
    VendingMachine* c = new VendingMachine();
    c->setState(new VendingDepositeState());

    std::cout << "------------------------" << std::endl;

    c->BuyProduct(5);
    c->TakeProduct();

    std::cout << "------------------------" << std::endl;

    c->BuyProduct(6);
    c->TakeProduct();

    std::cout << "------------------------" << std::endl;

    c->BuyProduct(2);

    c->BuyProduct(8);
    c->TakeProduct();

    std::cout << "------------------------" << std::endl;

}
