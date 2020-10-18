#include <iostream>
using namespace std;

class OrderProcessTemplate
{
    public:
        bool isGift;
        virtual void doSelect( void ) = 0;
        virtual void doPayment( void ) = 0;
        virtual void doDelivery( void ) = 0;

        void giftWrap()
        {
            std::cout<<"Gift wrap successfull" << std::endl;
        }

        void processOrder(bool isGift)
        {
            doSelect();
            doPayment();
            if (isGift) {
                giftWrap();
            }
            doDelivery();
        }
};


class NetOrder: public OrderProcessTemplate
{
    public:
        void doSelect( void )
        {
            std::cout<<"Item added to online shopping cart" << std::endl;
            std::cout<<"Get gift wrap preference" << std::endl;
            std::cout<<"Get delivery address." << std::endl;
        }

        void doPayment( void )
        {
            std::cout<< "Online Payment through Netbanking, card or Paytm" << std::endl;
        }

        void doDelivery( void )
        {
            std::cout<< "Ship the item through post to delivery address" << std::endl;
        }
};

class StoreOrder: public OrderProcessTemplate
{
    public:
        void doSelect( void )
        {
            std::cout<<"Customer chooses the item from shelf." << std::endl;
        }

        void doPayment( void )
        {
            std::cout<<"Pays at counter through cash/POS" << std::endl;
        }

        void doDelivery( void )
        {
            std::cout<<"Item deliverd to in delivery counter." << std::endl;
        }

};

//TemplateMethodPatternClient
int main()
{
    OrderProcessTemplate* netOrder = new NetOrder();
    netOrder->processOrder(true);
    OrderProcessTemplate* storeOrder = new StoreOrder();
    storeOrder->processOrder(true);
}

