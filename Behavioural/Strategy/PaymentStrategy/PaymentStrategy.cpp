#include <iostream>
#include <string>
#include <stdio.h>
#include <list>

class PaymentStrategy {
    public:
        virtual void pay(int amount) = 0;
};

class CreditCardStrategy: public PaymentStrategy {
    private:
        std::string name;
        std::string cardNumber;
        std::string cvv;
        std::string dateOfExpiry;
    public:
        CreditCardStrategy(std::string nm, std::string ccNum, std::string cvv, std::string expiryDate): name(nm), cardNumber(ccNum), cvv(cvv), dateOfExpiry(expiryDate) {}

        void pay(int amount) {
            std::cout << amount << " paid with credit/debit card" << std::endl;
        }
};

class PaypalStrategy: public PaymentStrategy {
    private:
        std::string emailId;
        std::string password;

    public:
        PaypalStrategy(std::string email, std::string pwd):emailId(email), password(pwd) {}

        void pay(int amount) {
            std::cout << amount << " paid using Paypal." << std::endl;
        }

};

class Item {
    private:
        std::string upcCode;
        int price;
    public:
        Item(std::string upc, int cost): upcCode(upc), price(cost) {}

        std::string getUpcCode() {
            return upcCode;
        }
        int getPrice() {
            return price;
        }
};

class ShoppingCart {
    std::list<Item> items;
    public:
    void addItem(Item item){
        this->items.push_back(item);
    }

    int calculateTotal(){
        int sum = 0;
        for ( std::list<Item>::iterator it = items.begin(); it !=items.end(); ++it)
            sum += (*it).getPrice();
        return sum;
    }

    void pay(PaymentStrategy* paymentMethod){
        int amount = calculateTotal();
        paymentMethod->pay(amount);
    }
};

int main()
{
    ShoppingCart* cart = new ShoppingCart();

    Item* item1 = new Item("1234",10);
    Item* item2 = new Item("5678",40);

    cart->addItem(*item1);
    cart->addItem(*item2);

    //pay by paypal
    cart->pay(new PaypalStrategy("myemail@example.com", "mypwd"));

    //pay by credit card
    cart->pay(new CreditCardStrategy("Pankaj Kumar", "1234567890123456", "786", "12/15"));
}

